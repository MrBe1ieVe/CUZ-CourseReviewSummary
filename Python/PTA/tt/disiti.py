import tkinter as tk

class Mygui:
    def __init__(self):
        self.a1=0
        self.main_window=tk.Tk()
        self.main_window.geometry('600x500+100+100')     
        self.bottom_frame=tk.Frame(self.main_window)
        self.top_frame=tk.Frame(self.main_window)
        self.middle_frame=tk.Frame(self.main_window)
        b1 = tk.Checkbutton(self.main_window,text='换油',bd=5,command=self.a1)
        b1.pack()
        b2 = tk.Checkbutton(self.main_window,text='润滑油服务',bd=5,command=self.a2)
        b2.pack()
        b3 = tk.Checkbutton(self.main_window,text='散热器冲洗',bd=5,command=self.a3)
        b3.pack()
        b4 = tk.Checkbutton(self.main_window,text='传输冲洗',bd=5,command=self.a4)
        b4.pack()
        b5=tk.Checkbutton(self.main_window,text='检查',bd=5,command=self.a5)
        b5.pack()
        b6=tk.Checkbutton(self.main_window,text='消声器更换',bd=5,command=self.a6)
        b6.pack()
        b7=tk.Checkbutton(self.main_window,text='轮胎旋转',bd=5,command=self.a7)
        b7.pack()
        commond1=tk.Button(self.bottom_frame,text='计算总费用',command=self.do_something)
        commond1.pack()
        self.label1=tk.Label(self.bottom_frame,text='得到的费用总和是：    ')
        self.label1.pack()
        self.bottom_frame.pack(side='bottom')
        tk.mainloop()
    def a1(self):
        self.a1=0
    def a2(self):
        self.a2=0
    def a3(self):
        self.a3=0
    def a4(self):
        self.a4=0
    def a5(self):
        self.a5=0
    def a6(self):
        self.a6=0
    def a7(self):
        self.a7=0
    def do_something(self):
        result=0
        if self.a1==0:
            result+=30
        if self.a2==0:
            result+=20
        if self.a3==0:
            result+=40
        if self.a4==0:
            result+=100
        if self.a5==0:
            result+=35
        if self.a6==0:
            result+=200
        if self.a7==0:
            result+=20
        self.label1.config(text='得到的费用总和是：    '+str(result))
mygui=Mygui()