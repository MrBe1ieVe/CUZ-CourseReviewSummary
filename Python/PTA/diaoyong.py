import employee
class ProductionWorker(employee.Employee):
    def __init__(self,name,code,banci,salary):
        employee.Employee.__init__(self,name,code)
        self.__banci=banci
        self.__salary=salary
    def set_banci(self,banci):
        self.__banci=banci
    def set_salary(self,salary):
        self.__salary=salary
    def get_banci(self):
        return self._banci
    def get_salary(self):
        return self.__salary
    def __str__(self):
        return 'name:'+self.get_name() + \
               '\ncode:'+self.get_code() + \
               '\nbanci:'+self.__banci + \
               '\nsalary:'+self.__salary
a=input()
b=input()
c=input()
d=input()
e=(ProductionWorker(a,b,c,d))
print(e.__str__())
