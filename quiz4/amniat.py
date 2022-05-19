def check_registration_rules(**u_p):
	x = 0
	result = 0 
	main_list = []
	num_list = ["0" ,"1" , "2", "3", "4", "5","6","7","8","9"]
	for  i in u_p.keys():
		len_u = len(i)
		password = u_p[i]
		len_p = len(password)
		if i != "quera" and i != "codecup" and len_u >= 4 and len_p >= 6 :
			hasChar = False
			for j in password:
				if not(j in num_list) :
					hasChar = True
			
			if hasChar:
				main_list.append(i)
					 
	# print(main_list)		
	return main_list

# check_registration_rules(username='password', sadegh='He3@lsa', quera='kLS45@l$')
# check_registration_rules(saeed='1234567', ab='afj$L12')