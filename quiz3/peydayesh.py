def find(num1, num2, num3):
    first_num = num1
    secent_num = num2
    third_num = num3 
    all_num = [1 , 2, 3, 4]
    found = 0 
    for i in all_num:
    	if first_num == i :
    		i = 0
    	elif secent_num == i :
    		i = 0
    	elif third_num == i :
    		i = 0
    	elif i != 0 :
    		found =i
    return found


# find(1 , 2 , 4)
# find(1 , 4 , 3)

