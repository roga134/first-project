def calculator(n, m, li):
	flag = True
	count_manfi = 0
	count_mosbat = 0
	count = 0
	q = n % m
	w = int(n / m)
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
			c = w % 2
			count += 1
			ll = count % m
			pp = n - q + 1
			if count >= pp :
				if w == 0 :
					count_manfi += i
				else :
					count_mosbat += i
			elif flag == True:
				count_mosbat += i
				if ll == 0:
					flag = False
			elif flag == False :
				count_manfi += i
				if ll == 0 :
					flag = True
	final_num = count_mosbat - count_manfi
	print(final_num)



#calculator(8, 1, [1, 2, 3, 4, 5, 6, 7, 8]) # -4
calculator(8, 3, [1, 2, 3, 4, 5, 6, 7, 8]) # 6