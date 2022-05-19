def fruits(fruit_list):
	p = 0
	x = fruit_list
	result = {}
	for i in x :
		name = i['name']
		shape = i['shape']
		mass = i['mass']
		volume = i['volume']
		if shape == 'sphere' and mass >= 300 and mass <= 600 and volume >= 100 and volume <= 500 :
			if name in result.keys():
				print(result)
				counter = result[name] +1
				result[name]=counter
			else:
				result.update({name:1})

	return result



# v = (
#     		{'name':'apple', 'shape': 'sphere', 'mass': 350, 'volume': 120},
#     		{'name':'mango', 'shape': 'square', 'mass': 150, 'volume': 120}, 
#    			{'name':'lemon', 'shape': 'sphere', 'mass': 300, 'volume': 100},
#     		{'name':'apple', 'shape': 'sphere', 'mass': 500, 'volume': 250}
# 	)
# fruits(v)