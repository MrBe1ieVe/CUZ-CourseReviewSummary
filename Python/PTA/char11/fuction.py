import employee
class ShiftSupervisor(employee.Employee):
    def __init__(self,name,number,annual_salary,production_bonus):
        Employee.__init__(self,name,number)
        self.__annual_salary=annual_salary
        self.__production_bonus=production_bonus
        
        
    