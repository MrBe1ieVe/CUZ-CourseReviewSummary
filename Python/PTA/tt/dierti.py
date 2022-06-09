import tkinter
import tkinter.messagebox

class Mygui:
    def __init__(self):
        self.main_window=tkinter.Tk()
        self.main_window.geometry('300x200+100+100')     
        self.bottom_frame=tkinter.Frame(self.main_window)
        self.top_frame=tkinter.Frame(self.main_window)
        self.middle_frame=tkinter.Frame(self.main_window)
        self.label4=tkinter.Label(self.top_frame,text='转化得到的华氏温度是： ')
        self.label2=tkinter.Label(self.bottom_frame,text='     ')
        self.label3=tkinter.Label(self.bottom_frame,text='请输入摄氏度:     ')
        self.entry1=tkinter.Entry(self.bottom_frame,width=10)
        self.button1=tkinter.Button(self.bottom_frame,text='计算',command=self.calulate)
        self.label1=tkinter.Label(self.top_frame)
        self.label3.pack(side='left')
        self.entry1.pack(side='left')
        self.label2.pack(side='left')
        self.button1.pack(side='left')
        self.bottom_frame.pack(side='bottom')
        self.label4.pack(side='left')
        self.label1.pack(side='left')
        self.top_frame.pack(side='top')
        tkinter.mainloop()
    def calulate(self):
        result=0
        try:
            c=float(self.entry1.get())
            result=c*1.6+32
            self.label1.config(text=format(result,',.2f'))
        except:
            tkinter.messagebox.showinfo('错误','请重新输入摄氏度')
mygui=Mygui()