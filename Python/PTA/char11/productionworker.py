import employee
class ProductionWorker(employee.Employee):
    def __init__(self,name,number,code,salary):
        employee.Employee.__init__(self,name,number)
        self.__code=code
        self.__salary=salary
    def set_code(self,code):
        self.__code=code
    def set_salary(self,salary):
        self.__salary=salary
    def get_code(self):
            return self.__code
    def get_salary(self):
        return self.__salary
 #   def __str__(self):
  #      return '代码'+get_code(self)+'小时工资'+get_salary(self)
a=input()
b=input()
code=input()
salary=input()
e=ProductionWorker(a,b,code,salary)
print('姓名：'+e.get_name())
print('编号：'+e.get_number())
print('代码：'+e.get_code())
print('小时工资:'+e.get_salary())

    