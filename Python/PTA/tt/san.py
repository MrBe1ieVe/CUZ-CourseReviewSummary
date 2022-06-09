import tkinter
import tkinter.messagebox

class Mygui:
    def __init__(self):
        self.main_window=tkinter.Tk()
        self.main_window.geometry('300x200+100+100')     
        self.a1=0
        self.a2=0
        self.a3=0
        self.frame1=tkinter.Frame(self.main_window)
        self.frame2=tkinter.Frame(self.main_window)
        self.frame3=tkinter.Frame(self.main_window)
        self.button1=tkinter.Button(self.frame1,text='白天（上午6:00——下午5:59）    每分钟0.07元',command=self.b1)
        self.button2=tkinter.Button(self.frame1,text='晚上（下午6:00——晚上11:59）   每分钟0.12元',command=self.b2)
        self.button3=tkinter.Button(self.frame1,text='非高峰（半夜12:00——上午5:59） 每分钟0.05元',command=self.b3)
        self.button1.pack()
        self.button2.pack()
        self.button3.pack()
        self.label1=tkinter.Label(self.frame3,text='已选：')
        self.label1.pack()
        self.label2=tkinter.Label(self.frame3,text='输入时间：')
        self.label2.pack()
        self.entry1=tkinter.Entry(self.frame3)
        self.entry1.pack()
        self.label3=tkinter.Label(self.frame3,text='费用：')
        self.label3.pack()
        self.button5=tkinter.Button(self.frame3,text='计算',command=self.js)
        self.button5.pack()
        self.button8=tkinter.Button(self.frame2,text='Quit',command=self.main_window.destroy)
        self.button8.pack()
        self.frame1.pack()
        self.frame3.pack()
        self.frame2.pack(side='bottom')      
        tkinter.mainloop()
    def b1(self):
        if self.a2==1 or self.a3==1:
            self.a2=0
            self.a3=0
        self.a1=1    
        k=0.07
        self.label1.config(text='已选：白天')    
    def b2(self):
        if self.a1==1 or self.a3==1:
            self.a1=0
            self.a3=0
        self.a2=1    
        k=0.12
        self.label1.config(text='已选：晚上')    
    def b3(self):
        if self.a2==1 or self.a1==1:
            self.a2=0
            self.a1=0
        self.a3=1    
        k=0.05
        self.label1.config(text='已选：非高峰')
    def js(self):
        try:
            a=float(self.entry1.get())
            self.label3.config(text='费用'+str(format(a*(self.a1*0.07+self.a2*0.12+self.a3*0.05),',.2f')))
        except:
            tkinter.messagebox.showinfo('错误','请选择时间段并输入时间')
mygui=Mygui()