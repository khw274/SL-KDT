import torch
import matplotlib.pyplot as plt
from sklearn.metrics import f1_score


## ========================================================
## 함수이름 : train_one_epoch
## 반환결과 : 손실, 정확도
## ========================================================
def train_one_epoch(model, loader, loss_fn, optim, device):
    model.train()
    total_loss, correct, total = 0.0, 0, 0
    all_preds, all_targets = [], []  
    
    for x, y in loader:
        x = x.to(device, dtype=torch.float32)
        y = y.to(device, dtype=torch.float32)
        
        optim.zero_grad()
        logits = model(x)
        loss = loss_fn(logits, y)
        
        loss.backward()
        optim.step()
        
        total_loss += loss.item() * x.size(0)
        pred = (logits > 0.5).float()
        correct += (pred == y).sum().item()
        total += x.size(0)
        
        # F1 계산용 데이터 모으기
        all_preds.extend(pred.cpu().numpy())
        all_targets.extend(y.cpu().numpy())
    
    # F1 Score 계산
    f1 = f1_score(all_targets, all_preds)
    
    # 3개 값 반환
    return total_loss / total, correct / total, f1




## ========================================================
## 함수이름 : evaluate
## 함수기능 : 검증/테스트 시 사용
##           역전파 진행 하지 않음
## 반환결과 : 손실, 정확도, f1
## ========================================================
@torch.no_grad()
def evaluate(model, loader, loss_fn, device):
    model.eval()
    total_loss, correct, total = 0.0, 0, 0
    all_preds, all_targets = [], []  
    
    for x, y in loader:
        x = x.to(device, dtype=torch.float32)
        y = y.to(device, dtype=torch.float32)
        
        logits = model(x)
        loss = loss_fn(logits, y)
        
        total_loss += loss.item() * x.size(0)
        pred = (logits > 0.5).float()
        correct += (pred == y).sum().item()
        total += x.size(0)
        
        # F1 계산용 데이터 모으기
        all_preds.extend(pred.cpu().numpy())
        all_targets.extend(y.cpu().numpy())
    
    # F1 Score 계산
    f1 = f1_score(all_targets, all_preds)
    
    # 3개 값 반환
    return total_loss / total, correct / total, f1



## ========================================================
## 함수이름 : show_predictions
## 반환결과 :  - 
## ========================================================
@torch.no_grad()
def show_predictions(model, loader, class_names, device, n=8):
    model.eval()


    x, y = next(iter(loader))
    x = x.to(device, dtype=torch.float32)  # float32


    logits = model(x)
    
    ##-> loss 계산/역전파가 끝난 뒤 지표용으로만 CPU로 내림
    pred = (logits > 0.5).cpu().float()   # 임계값 0.5
    y = y.cpu()


    n = min(n, x.size(0))
    print("Sample predictions:")
    for i in range(n):
        gt   = class_names[int(y[i].item())]
        pd   = class_names[int(pred[i].item())]
        mark = "[O]" if gt == pd else "[X]"
        print(f"- GT: {gt:<5} | Pred: {pd:<5} {mark}")


## ========================================================
## 함수이름 : plot_history
## 반환결과 :  - 
## ========================================================
def plot_history(history, title="Training Curves"):
    epochs = list(range(1, len(history["train_loss"]) + 1))
    
    plt.figure(figsize=(15, 4))
    
    # Loss 그래프
    plt.subplot(1, 3, 1)
    plt.plot(epochs, history["train_loss"], label="train_loss", marker='o')
    plt.plot(epochs, history["val_loss"], label="val_loss", marker='s')
    plt.xlabel("Epoch")
    plt.ylabel("Loss")
    plt.title(f"{title} - Loss")
    plt.legend()
    plt.grid(True)
    
    # Accuracy 그래프
    plt.subplot(1, 3, 2)
    plt.plot(epochs, [a * 100 for a in history["train_acc"]], label="train_acc (%)", marker='o')
    plt.plot(epochs, [a * 100 for a in history["val_acc"]], label="val_acc (%)", marker='s')
    plt.xlabel("Epoch")
    plt.ylabel("Accuracy (%)")
    plt.title(f"{title} - Accuracy")
    plt.legend()
    plt.grid(True)
    
    # F1 Score 그래프 
    plt.subplot(1, 3, 3)
    plt.plot(epochs, [f * 100 for f in history["train_f1"]], label="train_f1 (%)", marker='o')
    plt.plot(epochs, [f * 100 for f in history["val_f1"]], label="val_f1 (%)", marker='s')
    plt.xlabel("Epoch")
    plt.ylabel("F1 Score (%)")
    plt.title(f"{title} - F1 Score")
    plt.legend()
    plt.grid(True)
    
    plt.tight_layout()
    plt.show()
