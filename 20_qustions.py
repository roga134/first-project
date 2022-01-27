# we can use this part in all of the AI its all pusetive word
yes_part = ['yes', "Yes", "ya", 'Ya', 'yeap', 'Yeap', 'yeah', 'Yeah', 'ok', 'Ok', 'no Im ok', 'no I am ok','I can continue', 'please continue', 'continue', 'I know', 'I know ', 'of course ', 'of course','Of course ', 'Of course', 'yea', 'Yea', 'some', 'lot', 'know', 'maby', 'yes,I do.', 'yes, I do','yes I do', 'I do']
#this code will import random for AI
import random
import datetime



# this part is 2 lists for using in AI 
questions_list = ['Are there twelve characters?','Is it eleven letters?','Is it ten letters?','Is not it professional?','Are there eight letters?','Are there seven letters?','Are there six letters?','Are there five letters?','Are there four letters?','Are they two letters','Are there three letters?','Is it pentagonal?','Is it hexagonal?','Is it a lozenge?','Is it a triangle?','Is it a rectangle?','Is it a square?','Is it pollen?','Can it fit in your hand?','Is it the background?','Do you crawl?','Does it fly?', 'is it big?','is it small ?','Does it fit in your pocket?','is it alive?' , 'is it man?' , 'is it woman?' , 'is it car?' , 'is it city?' , 'is it fruit' ,    ]
proper_noun_9 = [ 'cat'  , 'book' , 'dress' , 'guitar' , 'giraffe'  , 'keyboard'  , 'Bill Gates' , 'university' , 'photography' ]
questions_cat = ['alive' , 'animals' , 'animal' , 'feet' , '4 feet' , 'four feet' , 'wool' , 'short wool' , ]

#this part choos one word random from proper_noun_9
flag = True
if flag == True :
	random_word = random.sample(proper_noun_9 , k = 1)
	for i in random_word :
		flag = False


# this part will Conversion to string
flag2 = True
if flag2 == True :
	for j in questions_list :
		flag2 = False

#this print just mean rule of 20 questions 
print('******************** welcom to 20 questions ********************')
print('in this game my AI chooses one word and you can guess it in 20 questions ')
print('rule of this game : you can just ask 20 questions , AI just should say yes or no ')
print('ok , lets start')
print('now you can ask questions')
ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a '),replace('Does it have a', '').replace('can it ' , '').replace('Can it').replace('can it', '')


# this part can say good night and ... to you if you want to go 
def zone_time_part():
    date_now = datetime.datetime.now()
    time_now = float(date_now.strftime("%H"))
    if time_now >= 5 and time_now <= 10 :
        print('good morning')
    elif time_now >= 11 and time_now <= 16 :
        print('good noon')
    elif time_now >= 17 and time_now <= 21 :
        print('good after noon')
    else :
        print('good night')


# I choos 9 proper noun and first 3 is for mahdy and secend 3 for shervin and third 3 is for kiarash
# mahdy
def one_proper_noun():   # its cat
	count = 0 
	while :
		count = count + 1
		if count == 20 :
			print('ok you lose it was cat' + zone_time_part())
		elif ask_questions in questions_cat :
			print('yes')



#def two_proper_noun():





#def three_proper_noun():
	


#shervin 
#def four_proper_noun():
	

	

#def five_proper_noun():
	



#def six_proper_noun():
	
	


#kiarash
#def seven_proper_noun():
	

	


#def eight_proper_noun():
	



#def nine_proper_noun():
	



# this part will call def based on random word
if i == 'cat' :
	one_proper_noun()
elif i == 'book' :
	two_proper_noun()
elif i == 'dress' :
	three_proper_noun()
elif i == 'guitar' :
	four_proper_noun()
elif i == 'giraffe' :
	five_proper_noun()
elif i == 'keyboard' :
	six_proper_noun()
elif i == 'Bill Gates' :
	seven_proper_noun()
elif i == 'university' :
	eight_proper_noun()
elif i == 'photography' :
	nine_proper_noun()



