def words_check(text):
	cca = []
	bb = {}
	a = text.split()
	for i in a :
		p = i.casefold().capitalize()# part part of the text
		asd = a.count(i)
		if "!" in p :
			count_g(p)
			qe = p.count("!")
			g = count - qe
			if g == qe or g < qe :
				q = p.replace("!" , "" )
				cca.append(q)
		elif "#" in p :
			count_g(p)
			qr = p.count("#")
			g = count - qr
			if g == qr or g < qr: 
				e = p.replace("#" , "")
				cca.append(e)
		elif "_" in p :
			count_g(p)
			qqq = p.count("_")
			g = count - qqq
			if g == qqq or g < qqq :
				ee = p.replace("_" , "").replace("?" , "")
				cca.append(ee)
		elif "?" in p :
			count_g(p)
			t = p.count("?")
			g = count - t
			if g == t or g < t :
				ert = p.replace("?" , "")
				cca.append(ert)
		elif "'" in p  :
			count_g(p)
			t = p.count("'")
			g = count - t
			if g > t :
				er = p.replace("'" , "")
				cca.append(er)
		else :
			cca.append(p)
	b = sorted(cca)
	for j in b:
		bb[j] = asd
	print(bb)

def count_g(c):
	global count
	count = 0
	for w in c :
		count += 1




words_check('''hEllO My FriEnDs!!! thIS is A tEsT For your #p#r#o#b#l#e#m''')#{'A': 1, 'For': 1, 'Friends': 1, 'Hello': 1, 'Is': 1, 'My': 1, 'Test': 1, 'This': 1, 'Your': 1}
#words_check('''HeLLLO_O My________________FRIEND HOW ARE YOUUUUU?___? I Don'T KNow Y_O_U_R_N_A_M_E yet !!!!!!!!''')#{'Are': 1, 'Dont': 1, 'Hellloo': 1, 'How': 1, 'I': 1, 'Know': 1, 'Yet': 1, 'Yourname': 1, 'Youuuuu': 1}
