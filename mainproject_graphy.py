# this part we use Presentation for all of part like hi part and ...
# we using this part for feeling_part
feeling_good = ['I am good', 'Im good', 'Im not bad', 'I am not bad', 'Im perfect', 'I am perfect', 'tnx', 'Im ok',
                'I am ok', 'fine tnx', ' fine thank you', 'fine thanks', 'fine', 'I am fine', 'Im fine' , 'good' , 'fine' ]
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
small_game2 = ['its small' , 'its small ' , 'it is small' , 'it is small ' , 'small' , 'small ' , 'Small' , 'Small ']
True_game2 = ['its true' , 'its true ' , 'it is true ' , 'it is true' , 'true' , 'true ' , 'True' , 'True '] 
from tkinter import *
import tkinter.font
import tkinter as tk
from tkinter import ttk
from PIL import Image

project_graphy = tkinter.Tk()
project_graphy.title('*********AI*********')
project_graphy.configure(background = '#F2B33D' )
project_graphy.geometry('3000x1000')


text_box1 = tk.Label(project_graphy , text = '**************Welcome to my AI*************' , bg = '#F2B33D' , fg = 'black' , font = ('Comic Sans MS' , 38 , 'bold'))
text_box1.grid(row = 0 , column = 4   )


text_box2 = tk.Label(project_graphy , text = 'Hi' , bg = '#F2B33D' , fg = 'black' ,  font = ('Comic Sans MS' , 24 , 'bold'))
text_box2.grid(row = 1 , column = 4 )


text_box3 = tk.Label(project_graphy, text="your text" , fg = 'black' , bg = '#F2B33D' , font = ('Comic Sans MS' , 27 , 'bold'))
text_box3.grid(row = 2, column = 0 )


input_box1 = Entry(project_graphy )
input_box1.grid(row = 2, column = 1 )


text_box4 = tk.Label(project_graphy, text = 'how are you?' , fg = "black" , bg = '#F2B33D' , font = ('Comic Sans MS' , 27 , 'bold'))


text_box5 = tk.Label(project_graphy, text="your text" , fg = 'black' , bg = '#F2B33D' , font = ('Comic Sans MS' , 27 , 'bold'))


input_box2 = Entry(project_graphy )


text_box6 = tk.Label(project_graphy , text = 'tnx God' , fg = 'black' , bg = '#F2B33D' ,font = ('Comic Sans MS' , 33 , 'bold') )



print(input_box1.get())




def new_text_world1():
	text_box4.grid(row = 0 , column = 4)
	text_box5.grid(row = 1, column = 0 )
	input_box2.grid(row = 1, column = 1 )
	button2.grid(row = 1, column = 3   )

print(input_box2.get())

def feeling() :
	if input_box2.get() in feeling_good :
		text_box6.grid(row = 0 , column= 4) 
		text_box4.after(500 , text_box4.destroy())
		text_box5.after(500 , text_box5.destroy())
		input_box2.after(500 , input_box2.destroy())
		button2.after(500 , button2.destroy())
		




def delete_all1():
	text_box1.after(500, text_box1.destroy())
	text_box2.after(500, text_box2.destroy())
	text_box3.after(500, text_box3.destroy())
	button1.after(500, button1.destroy())
	input_box1.after(500, input_box1.destroy())
	new_text_world1()


def hi_part() :
	if input_box1.get() in hi_part_array :
		delete_all1()
	else :
		exit()

button1 = Button(project_graphy , text = "if your typing is done click here"  , font = ('Comic Sans MS' , 27 , 'bold') , fg = 'black' , bg = '#F2B33D' , command = hi_part )
button1.grid(row = 2, column = 2   )

button2 = Button(project_graphy , text = "if your typing is done click here"  , font = ('Comic Sans MS' , 27 , 'bold') , fg = 'black' , bg = '#F2B33D' , command = feeling )


project_graphy.mainloop()