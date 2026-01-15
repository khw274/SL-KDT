# D1010_WORK
#______________________________________________
# 28.3 연습문제: 단어 단위 N-gram 만들기
#______________________________________________
n = int(input())
text = input()
words = text.split()       
 
if (n > len(words)):
    print('wrong')
    
else:
    n_gram = zip(*[words[i:] for i in range(n)])                          
    for i in n_gram:
        print(i)
#______________________________________________
# 28.4 심사문제: 파일에서 회문인 단어 출력하기       
#______________________________________________
def readTxt():
    with open("./words.txt", mode = 'r') as f:
        
        while(1):
        
            txt = f.readline()
            txt = txt.rstrip('\n') # \n 문자 제거
            
            if not txt:           # 파일 끝에 도달하면 종료
                break
            
            if(txt == txt[::-1]):
                print(txt)
            
readTxt()
#______________________________________________
# 34.5 연습문제: 게임 캐릭터 클래스 만들기
#______________________________________________
class Knight:
    def __init__(self, health, mana, armor):
        self.health = health
        self.mana = mana
        self.armor = armor
        
    def slash(self):
        print("베기")                                           
 
x = Knight(health=542.4, mana=210.3, armor=38)
print(x.health, x.mana, x.armor)
x.slash()
#______________________________________________
# 34.6 심사문제: 게임 캐릭터 클래스 만들기
#______________________________________________
class Annie:
    def __init__(self, health, mana, ability_power):
        self.health = health
        self.mana = mana
        self.ability_power = ability_power
        
    def tibbers(self):
        damage = self.ability_power * 0.65 + 400
        print(f"티버: 피해량 {damage}")

health, mana, ability_power = map(float, input().split())
 
x = Annie(health=health, mana=mana, ability_power=ability_power)
x.tibbers()