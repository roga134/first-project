feeling_good = ['I am good', 'Im good', 'Im not bad', 'I am not bad', 'Im perfect', 'I am perfect', 'tnx', 'Im ok',
                'I am ok', 'fine tnx', ' fine thank you', 'fine thanks', 'fine', 'I am fine', 'Im fine' , 'good' , 'fine' ]
yes_part = ['yes', "Yes", "ya", 'Ya', 'yeap', 'Yeap', 'yeah', 'Yeah', 'ok', 'Ok', 'no Im ok', 'no I am ok',
            'I can continue', 'please continue', 'continue', 'I know', 'I know ', 'of course ', 'of course',
            'Of course ', 'Of course', 'yea', 'Yea', 'some', 'lot', 'know', 'maby', 'yes,I do.', 'yes, I do',
            'yes I do', 'I do']
hi_part_array = ["hi", "Hi", "hello", "Hello", "hey", "Hey" , 'hi ' , 'Hi ' , 'Hello ' , 'hello ' , 'Hey ' , 'hey ']
good_country = ['America', 'Russia', 'Japan', 'Canada', 'Turkish', 'Netherlands', 'Europe']
good_weather = ['good', 'so so', 'it is not bad', 'its not bad', 'it isnt bad']
small_game2 = ['its small' , 'its small ' , 'it is small' , 'it is small ' , 'small' , 'small ' , 'Small' , 'Small ']
True_game2 = ['its true' , 'its true ' , 'it is true ' , 'it is true' , 'true' , 'true ' , 'True' , 'True '] 



from requests import *
import datetime
from tkinter import *
import tkinter.font
import tkinter as tk
from tkinter import ttk
from PIL import Image
import sys
from time import sleep
import os
import time




project_graphy = tkinter.Tk()
project_graphy.title('*********AI*********')
project_graphy.resizable(0,0)
project_graphy.configure(background = '#F2B33D' )
project_graphy.geometry('1000x700')






def good_n_m():
	date_now = datetime.datetime.now()
	time_now = float(date_now.strftime("%H"))
	delete_all_text()
	if time_now >= 5 and time_now <= 20 :
		text_one_val.set("have good day")
	else :
		text_two_val.set("good night")


def set():
	text_one_val.set("")
	text_two_val.set("")
	if_input.set("")






def delete_all_text():
	text_one_val.set("")
	text_two_val.set("")
	set()
	button1.destroy()
	button2.destroy()
	button3.destroy()
	button4.destroy()
	button5.destroy()
	button6.destroy()
	text_box_main.after(0 , text_box_main.destroy)
	input_box_main.after(0 , input_box_main.destroy)
	but_exit.after(0 , but_exit.destroy())
	




def main():
	global text_box_main
	global if_input
	global input_box_main
	global but_exit


	text_box_main = tk.Label(project_graphy, text="your text" , fg = 'black', bg = '#F2B33D' , font = ('Comic Sans MS' , 27 ))
	text_box_main.place(x=310 , y = 115)

	if_input = StringVar()

	input_box_main = Entry(project_graphy , textvariable = if_input )
	input_box_main.place(x = 430 , y = 125)
	
	user_pick = if_input.get()


	but_exit = Button(project_graphy , text = "Exit"  , font = ('Comic Sans MS' , 30 ) , fg = 'black' , bg = '#F2B33D' , command = good_n_m)
	but_exit.place(x = 450 , y = 210)


#asd
	

def all_text():
	global text_one_val
	global text_two_val
	global bu_y
	global bu_n
	global button1
	global button2
	global button3
	global button4
	global button5
	global button6
	global name_input
	global if_input


	text_one_val = StringVar()
	text_one = tk.Label(project_graphy , textvariable = text_one_val , bg = '#F2B33D' , fg = "black"  , font = ( 'Comic Sans MS' , 33 ))
	text_one.pack()

	text_two_val = StringVar()
	text_two = tk.Label(project_graphy , textvariable = text_two_val , bg = '#F2B33D' , fg = "black" ,  font = ( 'Comic Sans MS' , 33 ))
	text_two.pack()


	text_one_val.set("**************Welcome to my AI*************")
	text_two_val.set("Hi")
	


	button1 = Button(project_graphy , text = "Click"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = hi_part )
	button1.place(x = 450 , y = 155)
		

	button2 = Button(project_graphy , text = "Click"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = feeling )


	button3 = Button(project_graphy , text = "Click"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = name )


	button4 = Button(project_graphy , text = "Click" , font = ('Comic Sans MS' , 27 ) , fg = "black" , bg = "#F2B33D" , command = country)


	button5 = Button(project_graphy, text = "Click" , font = ('Comic Sans MS' , 27 ) , fg = "black" , bg = "#F2B33D" , command = city )


	button6 = Button(project_graphy, text = "Click" , font = ('Comic Sans MS' , 27 ) , fg = "black" , bg = "#F2B33D" , command = info_city )



	bu_y = Button(project_graphy , text = "Yes" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 27 , ) , command = speak_yes)


	bu_n = Button(project_graphy , text = "No" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 27 , ) , command = speak_no)



	


def hi_part() :
	user_pick = if_input.get()
	print(user_pick)
	if user_pick in hi_part_array :
		set()
		new_text_world1()
	else :
		set()
		speak_yes_no()



def new_text_world1():
	button1.after(0 , button1.destroy())
	text_one_val.set('how are you?')
	button2.place(x = 450 , y = 155)


def feeling():
	button2.destroy()
	user_pick = if_input.get()
	if user_pick in feeling_good :
		set()
		text_one_val.set('tnx God')
		text_two_val.set("whats your name?")
		button3.place(x = 450 , y = 155)
	else :
		set()
		text_one_val.set('you get better')
		text_two_val.set("whats your name?")
		button3.place(x = 450 , y = 155)


def name():
	button3.destroy()
	user_pick = if_input.get()
	set()
	text_one_val.set("nice to meet you " + user_pick.replace('my name is ', "").replace('Im ', '').replace('my first name is ', '').replace('my last name is ', ''))
	text_two_val.set("where are you from?")
	button4.place(x = 450 , y = 155)
	




def country():
	user_pick = if_input.get().replace('Im from ', "").replace('I am from ', '').replace('my country is ', '')
	set()
	if user_pick in good_country : 
		text_one_val.set("thats nice, " + user_pick + " is good country")
		text_two_val.set('do you want to know about your city like weather , location and ...?')
		button5.place(x = 450 , y = 155)
	else : 
		text_one_val.set("you can try and travel to good country" )
		text_two_val.set('do you want to know some informaition about your city?')
		button5.place(x = 450 , y = 155)


def city():
	user_pick = if_input.get()
	set()
	if user_pick in yes_part:
		button5.destroy()
		text_one_val.set("so please tell me your city")
		button6.place(x = 450 , y = 155)
	else :
		print("hi")


def info_city():
	user_pick = if_input.get()
	set()
	first_name_of_city = user_pick[:1]
	upper_first_name_of_city = str.upper(first_name_of_city)
	replace_first_name_of_cirt = user_pick.replace(first_name_of_city , upper_first_name_of_city)
	pasokh = get("https://api.openweathermap.org/data/2.5/weather?q="+replace_first_name_of_cirt+"&appid=33b6279f4b2c6787c70a5e62120ccbb6")
	comlite_know_city = pasokh.json()
	import_info_city = comlite_know_city.pop('coord' , 'base' , 'base' , 'temp_min' , 'temp_max' , 'pressure' , 'humidity' , 'visibility' , 'clouds' , 'dt' , 'sys' , 'sunrise' , 'sunset' , 'timezone' , 'name' , 'cod')
	text_one_val.set(comlite_know_city)
	print(comlite_know_city)







def speak_yes_no():
	text_box_main.destroy()
	input_box_main.destroy()
	button1.destroy()
	but_exit.destroy()


	text_one_val.set("do you want to speak with me ?")
	bu_y.place(x = 400 , y = 100)
	bu_n.place(x = 510 , y = 100)


def speak_yes():
	set()
	bu_y.destroy()
	bu_n.destroy()
	main()
	new_text_world1()

def speak_no():
	bu_y.destroy()
	bu_n.destroy()
	good_n_m()




	






main()
all_text()
project_graphy.mainloop()