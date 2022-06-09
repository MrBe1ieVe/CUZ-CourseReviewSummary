import person
class Customer(person.Person):
    def __init__(self,name,address,phone,typecode,flag):
        person.Person.__init__(self,name,address,phone)
        self.typecode=typecode
        self.flag=flag
    def set_typecode(self,typecode):
        self.__typecode=typecode
    def set_flag(self,flag):
        self.__flag=flag
    def get_typecode(self):
        return self.__typecode
    def get_flag(self):
        return self.__flag
    def __str__(self):
        return 'name:'+self.get_name() + \
               '\naddress:'+self.get_address() + \
               '\nphone:'+self.get_phone() + \
               '\ntypecode:'+self.__typecode + \
               '\nflag:'+self.__flag
a=input()
b=input()
c=input()
d=input()
e=input()
f=Customer(a,b,c,d,e)
print(f.__str__())