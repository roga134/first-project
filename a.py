from math import *
from requests import *
from time import *
#from pygame import mixer
bale_part = ['BALE' , 'bale' , 'bale ' , 'BALE ' , 'Bale ' , 'Bale',' BALE' , 'bAlE' , ' bAlE' , 'bAlE ' , 'BaLe' , ' BaLe' , 'BaLe ' , ' Bale' , 'Bale ' , 'bAle' , ' bAle' , 'bAle ' , 'baLe' , ' baLe' , 'baLe ' , 'balE' , ' balE' , 'balE ' ]

print("nam karbari khodeto type kon?")
a=input("")
print("nam karbari" , a)
print("ahle kojai? ahale iran hasti?")
b=input("")

if b in bale_part :
    print("khosh bakhtim")




print("aya mi khohi havae amroz ro behet nshon bedam?")
c=input("")


def api():
    pr = print('do want to undrestand weather of you city?')
    city = input()
    if city in bale_part:
        print('ok tell me your city')
    else :
        exit()
    city2 = str(input())
    c = city2[:1]
    oo = str.upper(c)
    pq = city2.replace(oo , c)
    pasokh = get("https://api.openweathermap.org/data/2.5/weather?q="+pq+"&appid=33b6279f4b2c6787c70a5e62120ccbb6")
    o = pasokh.json()
    return o    


print(api())




print("aya mi khohi bazi koni?")
d = input("")

if d in bale_part :
    print("bazi ene ke")
    print("se ta gozine mi dim har kodam ro entkhab konid barat baz mi konim")
    print("ke faghat yki az on doroste")
    print("moafagh bashi")
    
else:
    print("bazi ra nemi avaram")
    exit()

sleep(2)

print("1 2 3 kodam doroste?")
e=input("")

if e == "2" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

print("1 2 3 kodom doroste entkhab kon?")
f=input("")

if f == "1":
    print("berim soal badi")

else:
    print("shoma bakhti")
    exit()

print("1 2 3 kodam doroste entkhab kon?")
g=input("")

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

print("avalesh j dare va akhresh n dare?")
i=input("")

if i == "japon" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

print("avalesh a akharesh a dare?")
j=input("")

if j == "amrika" :
    print("berim soal badi")

else:
    print("shoma bakhtid")
    exit()

print("avalesh a akharesh n dare?")
k=input("")

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

print("paytakhte iran kojast?")
n=input("")

if n == "tehran" :
    print("berim soal badi")

else:
    print("bakhtid")
    exit()

print("aval morgh bode ya yokhme morgh?")
m=input("")

if m == "morgh" :
    print("berim soal badi")

else:
    print("bakhti")
    exit()

print("589 / 2 * 690 ** 2 chand mi she")
o=input("")

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


