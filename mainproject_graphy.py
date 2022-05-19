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
		tx_end1 = Label(project_graphy , text = "have good day" , font = ('Comic Sans MS' , 30 ) , bg = "#F2B33D" , fg = "black").pack()
	else :
		Label(project_graphy , text = "good night" , font = ('Comic Sans MS' , 30 ) , bg = "#F2B33D" , fg = "black").pack()


def set():
	if_input.set("")






def delete_all_text():
	text_box1.destroy()
	text_box2.destroy()
	text_box3.destroy()
	text_box4.destroy()
	text_box5.destroy()
	text_box6.destroy()
	text_box7.destroy()
	text_box8.destroy()
	text_box9.destroy()
	text_box10.destroy()
	set()
	button1.destroy()
	button2.destroy()
	button3.destroy()
	button4.destroy()
	text_box_main.after(0 , text_box_main.destroy)
	input_box_main.after(0 , input_box_main.destroy)
	but_exit.after(0 , but_exit.destroy())
	




def main():
	global text_box_main
	global if_input
	global input_box_main
	global but_exit
	global name_input

	name_input=""

	text_box_main = tk.Label(project_graphy, text="your text" , fg = 'black', bg = '#F2B33D' , font = ('Comic Sans MS' , 27 ))
	text_box_main.place(x=290 , y = 115)

	if_input = StringVar()

	input_box_main = Entry(project_graphy , textvariable = if_input )
	input_box_main.place(x = 410 , y = 125)
	
	user_pick = if_input.get()


	but_exit = Button(project_graphy , text = "Exit"  , font = ('Comic Sans MS' , 30 ) , fg = 'black' , bg = '#F2B33D' , command = good_n_m)
	but_exit.place(x = 450 , y = 210)



	

def all_text():
	global text_box1
	global text_box2
	global text_box3
	global text_box4
	global text_box5
	global text_box6
	global text_box7
	global text_box8
	global text_box9
	global text_box10
	global la_y_n
	global bu_y
	global bu_n
	global button1
	global button2
	global button3
	global button4
	global name_input
	global if_input


	text_one_val = StringVar()
	text_one = tk.Label(project_graphy , textvariable = text_one_val , bg =)



	text_box1 = tk.Label(project_graphy , text = '**************Welcome to my AI*************' ,bg = '#F2B33D'  , fg = 'black' , font = ( 'Comic Sans MS' , 33 ))#welcom
	text_box1.pack()


	text_box2 = tk.Label(project_graphy , text = 'Hi' , bg = '#F2B33D', fg = 'black' ,  font = ('Comic Sans MS' , 24 ))
	text_box2.pack()
		

	text_box3 = tk.Label(project_graphy, text = 'how are you?' , fg = "black" , bg = '#F2B33D' , font = ('Comic Sans MS' , 27 ))


	text_box4 = tk.Label(project_graphy , text = 'tnx God' , fg = 'black' , bg = '#F2B33D' ,font = ('Comic Sans MS' , 33 ) )


	text_box5 = tk.Label(project_graphy, text = 'you get better' , fg = 'black' , bg = '#F2B33D' , font = ('Comic Sans MS' , 33 ))


	text_box6 = tk.Label(project_graphy, text = "whats your name?" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 33 ))

	name_input = StringVar()
	text_box7 = tk.Label(project_graphy, textvariable = name_input, fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 33 ))
	


	text_box8 = tk.Label(project_graphy, text = "where are you from?" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 33 ))


	text_box9 = tk.Label(project_graphy, text = "thats nice, " +if_input.get() + " is good country", fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 33 ))


	text_box10 = tk.Label(project_graphy, text = "you can try and travel to good country" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 33 ))


	la_y_n = Label(project_graphy, text = "do you want to speak with me ?" , fg = "black" , bg = "#F2B33D" , font = ('Comic Sans MS' , 27))


	button1 = Button(project_graphy , text = "click"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = hi_part )
	button1.place(x = 290 , y = 155)
		

	button2 = Button(project_graphy , text = "feeling"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = feeling )


	button3 = Button(project_graphy , text = "name"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = name )


	button4 = Button(project_graphy , text = "country" , font = ('Comic Sans MS' , 27 ) , fg = "black" , bg = "#F2B33D" , command = country)


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
	text_box1.after(0 , text_box1.destroy())# welcome
	text_box2.after(0 , text_box2.destroy())# hi
	button1.after(0 , button1.destroy())
	text_box3.pack()# how are you
	button2.place( x = 290 , y = 155)


def feeling() :
	text_box3.destroy()
	button2.destroy()
	user_pick = if_input.get()
	if user_pick in feeling_good :
		set()
		text_box4.pack() # tnx god
		text_box6.pack()#whats your name
		button3.place(x = 290 , y = 155)
	else :
		set()
		text_box5.pack()# you get better
		text_box6.pack()#whats your name
		button3.place(x = 290 , y = 155)


def name():
	global text_box7
	global name_input 
	name_input.set("nice to meet you " + if_input.get().replace('my name is ', "").replace('Im ', '').replace('my first name is ', '').replace('my last name is ', ''))
	button3.destroy()
	text_box4.destroy()
	text_box5.destroy()
	text_box6.destroy()
	set()
	text_box7.pack()
	text_box8.pack()
	button4.place(x = 290 , y = 155)
	



def country():
	text_box8.destroy()
	button4.destroy()
	if user_pick in good_country : 
		name_input.set("thats nice, " + if_input.get().replace('my name is ', "").replace('Im ', '').replace('my first name is ', '').replace('my last name is ', '') + " is good country")
	else : 
		name_input.set("you can try and travel to good country" )




def speak_yes_no():
	text_box1.destroy()
	text_box2.destroy()
	text_box_main.destroy()
	input_box_main.destroy()
	button1.destroy()
	but_exit.destroy()


	la_y_n.pack()
	bu_y.place(x = 400 , y = 100)
	bu_n.place(x = 510 , y = 100)


def speak_yes():
	la_y_n.destroy()
	bu_y.destroy()
	bu_n.destroy()
	main()
	new_text_world1()

def speak_no():
	la_y_n.destroy()
	bu_y.destroy()
	bu_n.destroy()
	good_n_m()




	






main()
all_text()
project_graphy.mainloop()
