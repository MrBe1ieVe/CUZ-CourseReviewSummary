import tkinter
class House:
    def __init__(self):
        self.main_window=tkinter.Tk()
        self.canvas =tkinter.Canvas(self.main_window,width=200,height=200,bg='yellow')
        self.canvas.create_line(88,0,0,88,188,88,88,0)
        self.canvas.create_rectangle(0,88,188,188,outline='red')
        self.canvas.create_rectangle(10,110,30,150,outline='red')
        self.canvas.create_line(20,110,20,150)
        self.canvas.create_line(10,130,30,130)
        self.canvas.create_rectangle(120,140,180,160,outline='red')
        self.canvas.create_line(150,140,150,160)
        self.canvas.create_line(120,150,180,150)
        self.canvas.create_rectangle(80,170,110,188,outline='blue')
        self.canvas.pack()
my_house=House()
