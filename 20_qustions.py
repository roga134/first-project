# we can use this part in all of the AI its all pusetive word
yes_part = ['yes', "Yes", "ya", 'Ya', 'yeap', 'Yeap', 'yeah', 'Yeah', 'ok', 'Ok', 'no Im ok', 'no I am ok','I can continue', 'please continue', 'continue', 'I know', 'I know ', 'of course ', 'of course','Of course ', 'Of course', 'yea', 'Yea', 'some', 'lot', 'know', 'maby', 'yes,I do.', 'yes, I do','yes I do', 'I do']
#this code will import random for AI
import random
#this code will import time libery for AI
import datetime



# this part is 2 lists for using in AI 
proper_noun_9 = [ 'cat'  , 'book' , 'dress' , 'guitar' , 'giraffe'  , 'keyboard'  , 'Bill Gates' , 'university' , 'photography' ]
questions_cat = ['alive' , 'animals' , 'animal' , 'feet' , '4 feet' , 'four feet' , 'wool' , 'short wool' , 'made sound' , 'make sound' , '3 letters' , 'three letters' , 'run' , 'walk' , '3 characters' , 'three characters' , 'meat eater' , 'mammals' , 'mammal' ,  'small body' , 'pet' , 'pets' , 'domestic' , 'domestics' , 'pet animals']
questions_book = ['' ]
questions_dress = [ '']
questions_guitar = [ ' ']
questions_giraffe = [ '' ]
questions_keyboard = [ '' ]
questions_Bill_Gates = [ '' ]
questions_university = [ '' ]
questions_photography = [ '' ]

#this part choos one word random from proper_noun_9
flag = True
if flag == True :
	random_word = random.sample(proper_noun_9 , k = 1)
	for i in random_word :
		flag = False


print(i)


#this print just mean rule of 20 questions 
print('******************** welcom to 20 questions ********************')
print('in this game my AI chooses one word and you can guess it in 20 questions ')
print('rule of this game : you can just ask 20 questions , AI just should say yes or no ')
print('ok , lets start')
print('now you can ask questions')

# this part can say good night and ... to you if you want to go 
def zone_time_part():
    date_now = datetime.datetime.now()
    time_now = float(date_now.strftime("%H"))
    if time_now >= 5 and time_now <= 10 :
        print('good morning')
        exit()
    elif time_now >= 11 and time_now <= 16 :
        print('good noon')
        exit()
    elif time_now >= 17 and time_now <= 21 :
        print('good after noon')
        exit()
    else :
        print('good night')
        exit()


# I choos 9 proper noun and first 3 is for mahdy and secend 3 for shervin and third 3 is for kiarash
# mahdy
def one_proper_noun():   # its cat
	ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')
	count = 0 
	while 1 == 1:
		count = count + 1
		if count == 20 :
			print('ok you lose it was cat')
			print(zone_time_part())
		elif ask_questions in questions_cat :
			print('yes')
		elif ask_questions == 'cat':
			print('nice its correct')
			print(zone_time_part())
		else :
			print('no')
		ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')





def two_proper_noun(): # book
	ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')
	count = 0
	while 1 = 1 :
		count = count + 1
		if count == 20 :
			print('ok you lose it was book')
			print(zone_time_part())
		elif ask_questions in questions_book :
			print('yes')
		elif ask_questions == 'book' :
			print('nice its correct')
			print(zone_time_part())
		else :
			print('no')
		ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')







def three_proper_noun(): # its dress
	ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')
	count = 0 
	while 1 == 1:
		count = count + 1
		if count == 20 :
			print('ok you lose it was cat')
			print(zone_time_part())
		elif ask_questions in questions_dress :
			print('yes')
		elif ask_questions == 'dress':
			print('nice its correct')
			print(zone_time_part())
		else :
			print('no')
		ask_questions = input().replace('is it ' , '').replace(' is it ' , '').replace('is it' , '').replace('?' , '').replace(' ?' , '').replace(' ? ' , '').replace('does it have a' , '').replace('Does it have' , '').replace('does it have ' , '').replace('does it have a ' , '').replace('Does it have a', '').replace('can it ' , '').replace('Can it' , '').replace('can it', '').replace('it is' , '').replace('it is a' , '').replace('its ' , '').replace('its a' , '').replace('its a ' , '').replace('its' , '')

	

	


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
