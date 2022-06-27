def separator(ls):
	k = []# fard
	q = []# zoj
	for i in ls :
		b = i % 2
		if b == 0 :
			k.append(i)
		else :
			q.append(i)
	qwe = ( k, q)
	return qwe

#separator([1, 11, 5, 7, 3]) = ([], [1, 11, 5, 7, 3])
#separator([-3, -2, -1, 0, 1, 2, 3]) = ([-2, 0, 2], [-3, -1, 1, 3])