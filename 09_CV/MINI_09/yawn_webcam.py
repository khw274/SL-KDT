import cv2
import numpy as np
from joblib import load
import os
import urllib.request
import warnings
import time
import threading

try:
    import winsound
except ImportError:
    winsound = None

warnings.filterwarnings("ignore", category=UserWarning)

# =============================
# 설정
# =============================
MODEL_PATH = "./best_yawn_model.joblib"
CASCADE_PATH = "./haarcascade_frontalface_default.xml"
IMG_SIZE = (64, 64)
CLASSES = ["non_yawn", "yawn"]

# =============================
# Cascade 자동 다운로드
# =============================
def ensure_cascade():
    """Cascade 파일이 없으면 자동으로 다운로드"""
    if not os.path.exists(CASCADE_PATH):
        print("⚠️ Cascade 파일 없음. 다운로드 중...")
        url = "https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml"
        try:
            urllib.request.urlretrieve(url, CASCADE_PATH)
            print(f"✅ 다운로드 완료: {CASCADE_PATH}")
        except Exception as e:
            print(f"❌ 다운로드 실패: {e}")
            return False
    return True

# =============================
# 로드
# =============================
print("🔄 모델 로딩 중...")
try:
    model = load(MODEL_PATH)
    print("✅ 모델 로드 성공!")
except Exception as e:
    print(f"❌ 모델 로드 실패: {e}")
    exit()

print("🔄 Cascade 파일 확인 중...")
if not ensure_cascade():
    exit()

face_cascade = cv2.CascadeClassifier(CASCADE_PATH)
if face_cascade.empty() :
    print("❌ Cascade 파일을 로드할 수 없습니다.")
    exit()
else:
    print("✅ Cascade 로드 성공!")

# =============================
# 함수
# =============================
def extract_hog(gray_64):
    """64x64 그레이 이미지에서 HOG 특징 추출"""
    hog = cv2.HOGDescriptor(
        _winSize=IMG_SIZE,
        _blockSize=(16, 16),
        _blockStride=(8, 8),
        _cellSize=(8, 8),
        _nbins=9
    )
    return hog.compute(gray_64).flatten()

def detect_largest_face(gray):
    """가장 큰 얼굴 감지"""
    faces = face_cascade.detectMultiScale(
        gray, scaleFactor=1.1, minNeighbors=5, minSize=(40, 40)
    )
    if len(faces) == 0:
        return None
    x, y, w, h = max(faces, key=lambda b: b[2] * b[3])
    return (x, y, w, h)

def frame_to_feature(frame_bgr):
    """프레임에서 HOG 특징 추출"""
    gray = cv2.cvtColor(frame_bgr, cv2.COLOR_BGR2GRAY)
    box = detect_largest_face(gray)
    if box is None:
        return None, None

    x, y, w, h = box
    face = gray[y:y+h, x:x+w]
    face = cv2.resize(face, IMG_SIZE, interpolation=cv2.INTER_AREA)
    feat = extract_hog(face).astype(np.float32)
    return feat, box

def play_alarm():
    """경고음 재생"""
    if winsound:
        winsound.Beep(1000, 500)
    else:
        print('\a')

def main():
    """메인 루프"""
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("❌ 웹캠을 열 수 없습니다.")
        exit()

    print("\n✅ 웹캠 시작! (종료: q키)")
    print("=" * 50)

    # ==========================================
    # ⏱️ 하품 카운트 변수
    # ==========================================
    yawn_start_time = None
    yawn_total_count = 0
    is_yawning = False
    warning_active = False
    YAWN_LIMIT = 3
    MIN_YAWN_DURATION = 1.0

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        feat, box = frame_to_feature(frame)

        # 화면 표시용
        disp = frame.copy()

        # 이번 프레임에서 하품 감지되었는지
        this_frame_yawn = False

        if feat is None:
            cv2.putText(disp, "No face detected", (20, 40),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
        else:
            x, y, w, h = box

            # ✅ 예측
            X = feat.reshape(1, -1)
            pred = model.predict(X)[0]
            label = CLASSES[int(pred)]

            # 확률/스코어
            conf_text = ""
            if hasattr(model, "predict_proba"):
                proba = model.predict_proba(X)[0]
                conf = float(np.max(proba))
                conf_text = f" ({conf*100:.1f}%)"
            elif hasattr(model, "decision_function"):
                score = model.decision_function(X)
                conf_text = f" (score={float(np.ravel(score)[0]):.3f})"

            # ==========================================
            # 🎯 하품 감지 로직 (label == "yawn")
            # ==========================================
            if label == "yawn":
                this_frame_yawn = True
                color = (0, 0, 255)  # 빨강
                
                # 하품 시작 시간 기록
                if yawn_start_time is None:
                    yawn_start_time = time.time()
                    print("🚀 하품 시작!")
                
                # 지속시간 계산
                elapsed_time = time.time() - yawn_start_time
                
                # 1.5초 이상 지속 + 아직 카운트 안 했으면 카운트!
                if elapsed_time >= MIN_YAWN_DURATION and not is_yawning:
                    yawn_total_count += 1
                    is_yawning = True
                    print(f"✅ 하품 완료! 총 {yawn_total_count}회 (지속시간: {elapsed_time:.1f}s)")
                
                text_label = f"YAWN {elapsed_time:.1f}s{conf_text}"
            else:
                color = (0, 255, 0)  # 초록
                text_label = f"non_yawn{conf_text}"

            # 박스/텍스트
            cv2.rectangle(disp, (x, y), (x+w, y+h), color, 2)
            cv2.putText(disp, text_label, (x, y-10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)

        # ==========================================
        # ⏰ 하품 상태 전환 (끊기면 초기화)
        # ==========================================
        if not this_frame_yawn:
            if yawn_start_time is not None:
                print("⏹️ 하품 중단")
            yawn_start_time = None
            is_yawning = False

        # ==========================================
        # 📊 화면 정보 표시
        # ==========================================
        # 상단 검은색 배경
        cv2.rectangle(disp, (0, 0), (640, 80), (20, 20, 20), -1)
        
        # 카운트 표시
        count_text = f"Yawns: {yawn_total_count}/{YAWN_LIMIT}"
        if yawn_start_time:
            elapsed = time.time() - yawn_start_time
            count_text += f" | Current: {elapsed:.1f}s"
        
        cv2.putText(disp, count_text, (20, 40), 
                   cv2.FONT_HERSHEY_SIMPLEX, 1.0, (255, 255, 255), 2)
        
        # 진행도 바 (막대 그래프)
        bar_width = 200
        bar_height = 20
        bar_x, bar_y = 20, 55
        
        # 배경 바
        cv2.rectangle(disp, (bar_x, bar_y), (bar_x + bar_width, bar_y + bar_height), 
                     (100, 100, 100), -1)
        
        # 진행도
        if YAWN_LIMIT > 0:
            progress = min(yawn_total_count / YAWN_LIMIT, 1.0)
            filled_width = int(bar_width * progress)
            progress_color = (0, 255, 0) if yawn_total_count < YAWN_LIMIT else (0, 0, 255)
            cv2.rectangle(disp, (bar_x, bar_y), (bar_x + filled_width, bar_y + bar_height), 
                         progress_color, -1)
        
        # 테두리
        cv2.rectangle(disp, (bar_x, bar_y), (bar_x + bar_width, bar_y + bar_height), 
                     (200, 200, 200), 2)

        # ==========================================
        # 3회 경고 발령
        # ==========================================
        if yawn_total_count >= YAWN_LIMIT:
            # 빨간 경고 박스
            cv2.rectangle(disp, (0, 250), (640, 350), (0, 0, 100), -1)
            cv2.putText(disp, "WARNING", (230, 310),
                       cv2.FONT_HERSHEY_SIMPLEX, 1.3, (0, 0, 255), 3)
            
            # 경고음 재생 (쓰레드로)
            if not warning_active:
                warning_active = True
                threading.Thread(target=play_alarm).start()
                threading.Timer(2.0, lambda: globals().update({'warning_active': False})).start()

        cv2.imshow("HOG + Yawn Detector with Counter", disp)

        key = cv2.waitKey(1) & 0xFF
        if key == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
    print(f"\n✅ 프로그램 종료 (총 하품: {yawn_total_count}회)")

if __name__ == "__main__":
    main()
