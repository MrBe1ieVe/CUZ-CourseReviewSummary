import employee
class ShiftSupervisor(employee.Employee):
    def __init__(self,name,code,salary,jiangjin):
        employee.Employee.__init__(self,name,code)
        self.__salary=salary
        self.__jiangjin=jiangjin
    def set_salary(self,salary):
        self.__banci=banci
    def set_jiangjin(self,jiangjin):
        self.__jiangjin=jiangjin
    def get_salary(self):
        return self._salary
    def get_jiangjin(self):
        return self.__jiangjin
    def __str__(self):
        return 'name:'+self.get_name() + \
               '\ncode:'+self.get_code() + \
               '\nsalary:'+self.__salary + \
               '\njiangjin:'+self.__jiangjin
a=input()
b=input()
c=input()
d=input()
e=(ShiftSupervisor(a,b,c,d))
print(e.__str__())