def words_check(text):
	list_good_word = [ "a" , "b" , "c" , "d" , "e" , "f" , "g" , "h" , "i" , "j" , "k" , "l" , "m" , "n" , "o" , "p" , "q" , "r" ,"s" , "t" , "u" , "v" , "w" , "x" , "y" , "z"] 
	count_good_word = 0
	count_bad_word = 0
	dicth = {}
	list_made_for_dic = []
	list_wh_o_scored = text.split()# ['hEllO', 'My', 'FriEnDs!!!', 'thIS', 'is', 'A', 'tEsT', 'For', 'your', '#p#r#o#b#l#e#m']
	count = 0
	for i in list_wh_o_scored :
		number_count_word = list_wh_o_scored.count(i) # its count one word in list
		if_alpha = i.isalpha() # its undrestan # , ! , _ and ...
		if if_alpha == True :
			correct_word = i.casefold().capitalize()
			list_made_for_dic.append(correct_word) #Hello My This Is A Test For Your
		else :
			# i = FriEnDs!!! , #p#r#o#b#l#e#m
			for j in i :
				print(j)
				smaller_of_i = j.lower()
				count += 1
				if count == (len(i)+ 1) :
					count = 0 
					if count_good_word >= count_bad_word  :
						count_bad_word = 0
						count_bad_word = 0
						if smaller_of_i in list_good_word :
							count_good_word += 1
						else :
							count_bad_word += 1
				else :
					if smaller_of_i in list_good_word :
						count_good_word += 1
					else :
						count_bad_word += 1


	list_made_for_dic_sc = sorted(list_made_for_dic)
	for w in list_made_for_dic_sc :
		dicth[w] = number_count_word


words_check('''hEllO My FriEnDs!!! thIS is A tEsT For your #p#r#o#b#l#e#m''') #{'A': 1, 'For': 1, 'Friends': 1, 'Hello': 1, 'Is': 1, 'My': 1, 'Test': 1, 'This': 1, 'Your': 1}
#words_check('''HeLLLO_O My________________FRIEND HOW ARE YOUUUUU?___? I Don'T KNow Y_O_U_R_N_A_M_E yet !!!!!!!!''')#{'Are': 1, 'Dont': 1, 'Hellloo': 1, 'How': 1, 'I': 1, 'Know': 1, 'Yet': 1, 'Yourname': 1, 'Youuuuu': 1}
