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
small_game2 = ['its small' , 'its small ' , 'it is small' , 'it is small ' , 'small' , 'small ' , 'Small' , 'Small ']
True_game2 = ['its true' , 'its true ' , 'it is true ' , 'it is true' , 'true' , 'true ' , 'True' , 'True '] 
from tkinter import *
import tkinter.font
import tkinter as tk
from tkinter import ttk


project_graphy = tkinter.Tk()
project_graphy.title('AI')
project_graphy.configure(background = 'cyan' )
project_graphy.geometry('1000x1000')
text_box1 = tk.Label(project_graphy , text = '**************Welcome to my AI*************' , bg = 'cyan' , fg = 'black' , font = ('Comic Sans MS' , 32 , 'bold')).grid(row = 0 , column = 0)
text_box2 = tk.Label(project_graphy , text = 'Hi' , bg = 'cyan' , fg = 'black' ,  font = ('Comic Sans MS' , 27 , 'bold')).grid(row = 1 , column = 0)
text_box3 = tk.Label(project_graphy, text="your text" )
text_box3.grid(row = 2 , column = 0 )
input_box = Entry(project_graphy ).grid(row = 2 , column = 0)






project_graphy.mainloop()