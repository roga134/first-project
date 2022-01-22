# this part we use Presentation for all of part like hi part and ...
# we using this part for feeling_part
feeling_good = {'I am good', 'Im good', 'Im not bad', 'I am not bad', 'Im perfect', 'I am perfect', 'tnx', 'Im ok',
                'I am ok', 'fine tnx', ' fine thank you', 'fine thanks', 'fine', 'I am fine', 'Im fine'}
# we can use this part in all of the AI its all pusetive word
yes_part = {'yes', "Yes", "ya", 'Ya', 'yeap', 'Yeap', 'yeah', 'Yeah', 'ok', 'Ok', 'no Im ok', 'no I am ok',
            'I can continue', 'please continue', 'continue', 'I know', 'I know ', 'of course ', 'of course',
            'Of course ', 'Of course', 'yea', 'Yea', 'some', 'lot', 'know', 'maby', 'yes,I do.', 'yes, I do',
            'yes I do', 'I do'}
# we use this part for first or hi_part
hi_part_array = {"hi", "Hi", "hello", "Hello", "hey", "Hey"}
# this part is for county and its best country in my idea
good_country = {'America', 'Russia', 'Japan', 'Canada', 'Turkish', 'Netherlands', 'Europe'}
# this part using for time part and AI can undrestand your time
morning_time = {5, 6, 7, 8, 9, 10}
noon_time = {11, 12, 13, 14, 15, 16}
after_noon_time = {17, 18, 19, 20, 21}
night_time = {22, 23, 24, 1, 2, 3, 4}
# this part using for
good_weather = {'good', 'so so', 'it is not bad', 'its not bad', 'it isnt bad'}


# this part is for first part and AI can  undrestand do you want to speek with me or no and it part for hi
def hi_part():
    print('**************Welcome to my AI*************')
    print('Hi')
    global starting
    starting = input('')
    if starting not in hi_part_array:
        print("I said hi")
        starting = input('')
        if starting != hi_part:  # in this part if you wnat to speek with my AI can undrestand
            print('do you want speek to me?')
            want_speek = input('')
            if want_speek in yes_part:
                print('ok, we start again ')
            else:
                exit('good bye')


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
    name = input('').replace('my name is ', "").replace('Im ', '').replace('my first name is ', '').replace(
        'my last name is ', '')
    print('nice to meet you ' + name + ' thats nice name ')


# this part AI can undrestand where are from
def you_from_part():
    print('where are you from ?')
    your_country = input('').replace('Im from ', "").replace('I am from ', '').replace('my country is ', '')
    if your_country in good_country:
        print('thats nice, ' + your_country + ' is very good country')
    else:
        print('you can try and travel to good country ')


# this part AI can undrestand what time is in your place that you leave and we can use it in now and at the end of AI
def time_part():
    print('so, what time is there?')
    time = int(input(''))  # .replace(Additional_time , "") # we give time from a person who want speek with AI
    if time in morning_time:  # AI undrestand its morning
        print('good morning')
    elif time in noon_time:  # AI undrestand its noon
        print('good noon')
    elif time in after_noon_time:  # AI undrestand its after noon
        print('good after noon')

    elif time in night_time:  # AI undrestand its night
        print('good night')


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

