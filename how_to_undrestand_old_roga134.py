print('how old are you?')
y = int(input(''))
if y >0.0 and y < 6.0 :
    print('khordsal')
elif y >= 6.0 and y < 10.0 :
    print('koodak')
elif y >= 10.0 and y < 14.0:
    print('nojavan')
elif y >= 14.0 and y < 24.0 :
    print('javavn')
elif y >= 24.0 and y < 40.0 :
    print('bozorgsal')
else:
    print('miansal')