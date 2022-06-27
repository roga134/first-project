def calculator(n, m, li):
	flag2 = True
	flag = True
	count_manfi = 0
	count_mosbat = 0
	count = 0
	count2 = 0
	q = n % m
	w = int(n / m)
	if n = 0 :
		return 0
	for i in li :
		if q == 0 :
			kp = count % m
			if flag == True:
				count += 1
				count_mosbat += i
				if kp == 0 :
					flag = False
			elif flag == False : 
				count += 1
				count_manfi +=  i
				if kp == 0 :
					flag = True
		elif q != 0 :
			count2 += 1
			c = w % 2
			ll = count2 % m
			pp = n - q + 1
			if count2 >= pp :
				if w == 0 :
					count_manfi += i
				else :
					count_mosbat += i
			elif flag2 == True:
				count_mosbat += i
				if ll == 0:
					flag2 = False
			elif flag2 == False :
				count_manfi += i
				if ll == 0 :
					flag2 = True
	final_num = count_mosbat - count_manfi
	return final_num



#calculator(8, 1, [1, 2, 3, 4, 5, 6, 7, 8]) # -4
#calculator(8, 3, [1, 2, 3, 4, 5, 6, 7, 8]) # 6