print('enter your number :')
x = int(input())
if x > 1 :
    for i in range(2 , x):
        if (x % i) == 0:
            print('its not first number ')
            break
    else :
        print('its  first number ')
    