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






	


text_box_main = tk.Label(project_graphy, text="your text" , fg = 'black', bg = '#F2B33D' , font = ('Comic Sans MS' , 27 ))
text_box_main.place(x=290 , y = 105)
	
if_input = StringVar()

input_box_main = Entry(project_graphy , textvariable = if_input )
input_box_main.place(x = 410 , y = 115)
	
user_pick = if_input.get()

but_exit = Button(project_graphy , text = "Exit"  , font = ('Comic Sans MS' , 30 ) , fg = 'black' , bg = '#F2B33D' , command = good_night)
but_exit.place(x = 450 , y = 200)
	





def good_night():
	date_now = datetime.datetime.now()
	time_now = float(date_now.strftime("%H"))
	delete_all_text()
	if time_now >= 5 and time_now <= 20 :
		tx_end1 = Label(project_graphy , text = "have good day" , font = ('Comic Sans MS' , 30 ) , bg = "#F2B33D" , fg = "black").pack()
	else :
		Label(project_graphy , text = "good night" , font = ('Comic Sans MS' , 30 ) , bg = "#F2B33D" , fg = "black").pack()





def delete_all_text():
	print("34")
	text_box1.after(0 , text_box1.destroy())
	text_box2.after(0 , text_box2.destroy())
	text_box4.after(0 , text_box4.destroy())
	text_box6.after(0 , text_box6.destroy())
	text_box7.after(0 , text_box7.destroy())
	if_input.set("")
	button1.after(0, button1.destroy())
	button2.after(0, button2.destroy())
	text_box_main.after(0 , text_box_main.destroy)
	input_box_main.after(0 , input_box_main.destroy)
	but_exit.after(0 , but_exit.destroy())





# this part I make text box and input box
def text_input_button_part():
	#this part for get global the for using variable on all of project
	global time_now
	global text_box1
	global text_box2
	global text_box4
	global text_box6
	global text_box7
	global text_box8
	global text_box9
	global text_box10
	global text_box11
	global text_box12
	global button2
	global button1
	



	text_box1 = tk.Label(project_graphy , text = '**************Welcome to my AI*************' ,bg = '#F2B33D'  , fg = 'black' , font = ( 'Comic Sans MS' , 33 ))
	text_box1.pack()
	text_box2 = tk.Label(project_graphy , text = 'Hi' , bg = '#F2B33D', fg = 'black' ,  font = ('Comic Sans MS' , 24 ))
	text_box2.pack()
	main_text()
	


	text_box4 = tk.Label(project_graphy, text = 'how are you?' , fg = "black" , bg = '#F2B33D' , font = ('Comic Sans MS' , 27 ))


	

	text_box6 = tk.Label(project_graphy , text = 'tnx God' , fg = 'black' , bg = '#F2B33D' ,font = ('Comic Sans MS' , 33 ) )


	text_box7 = tk.Label(project_graphy, text = 'you get better' , fg = 'black' , bg = '#F2B33D' , font = ('Comic Sans MS' , 33 ))




	button1 = Button(project_graphy , text = "if your typing is done click here"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = hi_part )
	button1.place(x = 290 , y = 150)
	


	button2 = Button(project_graphy , text = "if your typing is done click here"  , font = ('Comic Sans MS' , 27 ) , fg = 'black' , bg = '#F2B33D' , command = feeling )



	





def hi_part() :
	user_pick = if_input.get()
	print(user_pick)
	if user_pick in hi_part_array :
		delete_all1()
	else :
		good_night()


def delete_all1():
	text_box1.after(100, text_box1.destroy())
	text_box2.after(100, text_box2.destroy())
	button1.after(100, button1.destroy())
	new_text_world1()

def new_text_world1():
	text_box4.pack()# how are you
	main_text()
	button2.place( x = 290 , y = 150)


def feeling() :
	user_pick = if_input.get()
	if user_pick in feeling_good :
		text_box4.after(0 , text_box4.destroy())
		button2.after(0 , button2.destroy())
		text_box6.pack() # tnx god
		new_text_world2()
	elif input_box2.get() not in feeling_good :
		text_box4.after(0 , text_box4.destroy())
		text_box5.after(0 , text_box5.destroy())
		input_box2.after(0 , input_box2.destroy())
		button2.after(0 , button2.destroy())
		text_box7.pack()# you get better
		new_text_world2()


def new_text_world2():
	button3.place(x = 290 , y = 150)







text_input_button_part()



	







project_graphy.mainloop()
