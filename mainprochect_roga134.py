# this part we use Presentation for all of part like hi part and ...
# we using this part for feeling_part
feeling_good = ['I am good', 'Im good', 'Im not bad', 'I am not bad', 'Im perfect', 'I am perfect', 'tnx', 'Im ok',
                'I am ok', 'fine tnx', ' fine thank you', 'fine thanks', 'fine', 'I am fine', 'Im fine']
# we can use this part in all of the AI its all pusetive word
yes_part = ['yes', "Yes", "ya", 'Ya', 'yeap', 'Yeap', 'yeah', 'Yeah', 'ok', 'Ok', 'no Im ok', 'no I am ok',
            'I can continue', 'please continue', 'continue', 'I know', 'I know ', 'of course ', 'of course',
            'Of course ', 'Of course', 'yea', 'Yea', 'some', 'lot', 'know', 'maby', 'yes,I do.', 'yes, I do',
            'yes I do', 'I do']
# we use this part for first or hi_part
hi_part_array = ["hi", "Hi", "hello", "Hello", "hey", "Hey" , 'hi ' , 'Hi ' , 'Hello ' , 'hello ' , 'Hey ' , 'hey ']
# this part is for county and its best country in my idea
good_country = ['America', 'Russia', 'Japan', 'Canada', 'Turkish', 'Netherlands', 'Europe']
# this part using for
good_weather = ['good', 'so so', 'it is not bad', 'its not bad', 'it isnt bad']
# this code will import request libery
from requests import *
# this code will import date libery
import datetime



# this part is for first part and AI can  undrestand do you want to speek with me or no and it part for hi
def hi_part():
    print('**************Welcome to my AI*************')
    print('Hi')
    global starting
    starting = input('')
    if starting not in hi_part_array:
        print("I said hi")
        starting = input('')
        if starting not in hi_part:  # in this part if you wnat to speek with my AI can undrestand
            print('do you want speek to me?')
            want_speek = input('')
            if want_speek in yes_part: # here I can undrestand do you wnat to speek with me or no
                print('ok, we start again ')
            else:
                print('good bye')
                exit()


# this part AI can undrestand how are you and we you continue ?
def feeling_part():
    print('how are you ? ')
    your_feeling = input('')
    if your_feeling in feeling_good:
        print('tnx god')
    else:
        print('You get better')
        print('are you ok to continue ?')
        continue_part = input('')
        if continue_part in yes_part:  # in this part if you are good we continue but you arent good ask from you to continue or no
            print('OK')
        else:
            exit('good bye')


# this part AI can undrestand whats your name
def name_part():
    print('whats your name?')
    name = input('').replace('my name is ', "").replace('Im ', '').replace('my first name is ', '').replace('my last name is ', '')# here if you say you name with my name is and ... I delete it and I use you name in under this line
    print('nice to meet you ' + name + ' thats nice name ')

# this def will undrestand your city and tell you about your city
def your_city_part():
    print('do you wnat to say your city name?')
    know_want_name_city = input()
    if know_want_name_city in yes_part :
        print('ok tell me you city')
        city_name = str(input())
        print('ok now do you want to know about your city like weather , location and ...')
        know_city = input()
        if know_city in yes_part:
            first_name_of_city = city_name[:1]
            upper_first_name_of_city = str.upper(first_name_of_city)
            replace_first_name_of_cirt = city_name.replace(first_name_of_city , upper_first_name_of_city)
            pasokh = get("https://api.openweathermap.org/data/2.5/weather?q="+replace_first_name_of_cirt+"&appid=33b6279f4b2c6787c70a5e62120ccbb6")
            comlite_know_city = pasokh.json()
            print(comlite_know_city)  
        else :
            exit('ok we can continue')
    else :
        print('ok we can continue')

# this part AI can undrestand where are from
def you_from_part():
    print('where are you from ?')
    your_country = input('').replace('Im from ', "").replace('I am from ', '').replace('my country is ', '')# here is like name_part() but I do that work with country
    if your_country in good_country: 
        print('thats nice, ' + your_country + ' is very good country')
        your_city_part()
    else:
        print('you can try and travel to good country ')
        your_city_part()

#this code say good morning or noon or .. from your time 
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




# this part AI can undrestand what time is in your place that you leave and we can use it in now and at the end of AI
def time_part():
    date_now = datetime.datetime.now()
    time_now = date_now.strftime("%H")
    print('do you wnat to know date?')
    know_date = input()
    if know_date in yes_part :
        print(date_now)
        zone_time_part()
    else :
        zone_time_part()


# in this time AI can undrestand weather of your country and you can undrestand I love cold weather
def weather_part():
    print('how is the weather like there?')
    weather = input('').replace('here is ', "").replace('Here is ', '').replace('here is so ', '').replace(
        'Here is so ', '').replace('its ', '').replace('it is ', '').replace('Its ', '').replace('It is ', '')
    if "cold" in weather:
        print('I love cold weather')
    elif weather in good_weather:
        print('thats nice but just I like cold weather')
    else:
        print('I dont like ' + weather + ' weather, just I like cold weather')


# in this part AI can undrestand how much you know about python and if you dont know I say a little about python and my  Experience
def know_python_part():
    print('how much you know about python ?')
    know_python_input = input("")
    if know_python_input in yes_part:
        print('thats nice ')
    else:
        print('I will tell you')
        print(
            'So far, I have learned that I can work with Python on a variety of tasks, such as blogging and artificial intelligence, and even as a hobby. For example, as a 16-year-old who loves programming and artificial intelligence, I write artificial intelligence to learn I was talking about artificial intelligence and I think the future revolves around artificial intelligence and hacking because they are like little monkeys and Python is like a new leek.')


# this part AI can undrestand you like python or no
def like_python_part():
    print('do you like python?')
    like_python = input('')
    if like_python in yes_part:
        print('me too')
    else:
        print("No problem because everyone has an opinion")


# this part I say a little about my self
def my_life_part():
    print("do you know who am I?")
    about_my_self = input("")
    if about_my_self in yes_part:
        print('ok, its Enough')
    else:
        print("ok I will tell you a litle about my self ")
        print('my name is mahdy Jangali and I am 16 year old I think its enough')


# this part AI can undrestand do you want to continue or no
def continue_undrestand_part():
    print("Would you like to continue?")
    like_continue = input("")
    if like_continue in yes_part:
        print('ok')
    else:
        if time == night_time:
            print('bye and good night')
        else:
            print('bye and have good day')


# this def is for all def is all of part one and its for starting part
def part_one_from_all_part():
    hi_part()
    feeling_part()
    name_part()
    you_from_part()
    time_part()
    weather_part()
    know_python_part()
    like_python_part()
    my_life_part()
    continue_undrestand_part()


# this part AI can undrestand do you want to play game or no
def question_to_go_game_part():
    print('do you want to play game ? ')
    input_game_question = input('')
    if input_game_question in yes_part:
        print('ok lets play game')
    else:
        print('we use def question here ')


# this game one and about a numbers
def game_one():
    count = 1
    print(
        'write range of number , first enter first number after that secend number for choose number beetween this range like  this first enter number1 after that AI want  your secend number  ')
    print('enter first number ')
    q = int(input())
    print('enter secend number')
    w = int(input())
    import random
    t = random.randint(q, w)
    print('now guess the number')
    a = int(input())
    while a != t:
        count = count + 1
        if a < t:
            print('The number you said is small, you have to say a bigger number ')
        elif a > t:
            print('The number you said is big , you have to say a smaller number')
        a = int(input())
    print('its true')
    print('you guess ' + str(count) + ' number')


def choos_game2():
    print(
        'game one is about numbers , AI choos one number beetween all of number and  you can choos beetween number and you shoud guess number')
    print('game 2 is about a world you can ask me 20 question and AI just answer yes or no ')
    print('now you choos 1 or 2')
    choos_game_number = input('')
    if choos_game_number in '1':
        game_one()
    elif choos_game_number in '2':
        print('we use game 2 here')


# this part is game and part 2 of all
def part_two_from_all_part():
    question_to_go_game_part()
    choos_game2()


# this part is for last and good bye
def good_bye():
    print('good bye')
    input('')


# we run from part 1 and part end
part_one_from_all_part()
# AI run part 2 or part game
part_two_from_all_part()

good_bye()

