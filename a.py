from math import *
from time import *


a=input("nam karbari khodeto type kon?")
print(a)
b=input("ahle kojai? ahale iran hasti?")

if b == "bale":
    print("khosh bakhtam")

else:
    print("in barname da keshvar shoma poshtibani ne mi shavad")
    exit()
    
print("aya mi khohi havae amroz ro behet nshon bedam?")
c = input()
def api():
    pasokh = requests.get("https://api.openweathermap.org/data/2.5/weather?q=&appid=33b6279f4b2c6787c70a5e62120ccbb6")
    o= pasokh.json()
    return o

api()

if c == "bale" :
    print(o)

d=input("aya mi khohi bazi koni?")

if d == "bale":
    print("bazi ene ke")
    print("se ta gozine mi dim har kodam ro entkhab konid barat baz mi konim")
    print("ke faghat yki az on doroste")
    print("moafagh bashi")
    
else:
    print("bazi ra nemi avaram")
    exit()

sleep(2)

e=input("1 2 3 kodam doroste?")

if e == "2" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

f=input("1 2 3 kodom doroste entkhab kon?")

if f == "1":
    print("berim soal badi")

else:
    print("shoma bakhti")
    exit()

g=input("1 2 3 kodam doroste entkhab kon?")

if g == "3" :
    print("berim soal badi")

else:
    print("shoma bakhti")
    exit()

print("age ta alan part nashodid az barname biron tabrik mi gam shoma barande shodid")

print("mi khod edame bedi va dar jame barndegan dor aval bashi va level khod ro bala bebarid")

h=input("bale ya na?")

if h == "bale" :
    print("pas soal ha ro mi arim")

else:
    print("pas khoda neghah dar")
    exit()

sleep(2)

print("be bakhshe dovom khosh omadi")
print("dar in bakhsh ma aval va akhar esm ye keshvar ro mi dim va shoma bayad esm keshvar ro baghid")

i=input("avalesh j dare va akhresh n dare?")

if i == "japon" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

j=input("avalesh a akharesh a dare?")

if j == "amrika" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

k=input("avalesh a akharesh n dare?")

if k == "alman" :
    print("berim soal badi")

else:
    print("shoma bakhti")
    exit()

sleep(2)

print("age ta alan part nashodid az barname biron tabrik mi gam shoma barande shodid")
print("shoma aya mi khohid be bakhshe sevom baravid?")

L=input("bale ya na")

if L == "bale" :
    print("pas be dor sevom ya hamon bakhshe payani khosh omadid")

else:
    print("emtiyaz shoma 100 ast")
    print("khoda neghahdar")
    exit()

print("dar in bakhsh az shoma soali porside mi shavad va shoma bayad paskh dahid")
print("se ta gozine bohton mi dim")
print("mofagh bashi")
print("har soal sakht tar mi she")

sleep(2)

n=input("paytakhte iran kojast?")

if n == "tehran" :
    print("berim soal badi")

else:
    print("bakhtid")
    exit()

m=input("aval morgh bode ya yokhme morgh?")

if m == "morgh" :
    print("berim soal badi")

else:
    print("bakhti")
    exit()

o=input("589 / 2 * 690 ** 2 chand mi she")

if o == "676,200" :
    print("berim soal badi")

else:
    print("bakhti")
    exit()

print("shoma barde bazi ma shodid")
print("sazandeghan in bazi")
print("kiarash noroozi : kod hai bazi ro neveshte")
print("bazi ro estadio k.n.p sakhte")
print("omidvaram az bazi ma lezat borde bashid")