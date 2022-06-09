import tkinter
import tkinter.messagebox

class Mygui:
    def __init__(self):
        self.main_window=tkinter.Tk()
        self.main_window.geometry('300x200+100+100')     
        self.buttom_frame=tkinter.Frame(self.main_window)
        self.top_frame=tkinter.Frame(self.main_window)
        self.frame3=tkinter.Frame(self.main_window)
        self.button1=tkinter.Button(self.buttom_frame,text='Show info',command=self.do_something)
        self.button2=tkinter.Button(self.buttom_frame,text='Quit',command=self.main_window.destroy)
        self.label1=tkinter.Label(self.buttom_frame,text='     ')
        self.label2=tkinter.Label(self.top_frame,text='wansheng')
        self.label3=tkinter.Label(self.top_frame,text='200207335')
        self.label4=tkinter.Label(self.top_frame,text='cuz')
        self.button1.pack(side='left')
        self.label1.pack(side='left')
        self.button2.pack(side='left')
        self.buttom_frame.pack(side='bottom')
        tkinter.mainloop()
    def do_something(self):
        self.label2.pack()
        self.label3.pack()
        self.label4.pack()
        self.top_frame.pack(side='top')
mygui=Mygui()