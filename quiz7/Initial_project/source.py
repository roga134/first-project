def words_check(text):
	a = text.split()
	for i in a :
		p = i.casefold().capitalize()
		if "!" in p :
			#qe = i.count()
			q = p.replace("!" , "" )
		elif "#" in p :
			qr = p.count("#")
			count_g(p)
def count_g(c):
	count = 0
	for w in c :
		count += 1
		p = int(count / 2)
	print(p)






words_check('''hEllO My FriEnDs!!! thIS is A tEsT For your #p#r#o#b#l#e#m''')#{'A': 1, 'For': 1, 'Friends': 1, 'Hello': 1, 'Is': 1, 'My': 1, 'Test': 1, 'This': 1, 'Your': 1}
#words_check('''HeLLLO_O My________________FRIEND HOW ARE YOUUUUU?___? I Don'T KNow Y_O_U_R_N_A_M_E yet !!!!!!!!''')#{'Are': 1, 'Dont': 1, 'Hellloo': 1, 'How': 1, 'I': 1, 'Know': 1, 'Yet': 1, 'Yourname': 1, 'Youuuuu': 1}