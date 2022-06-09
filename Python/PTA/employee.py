class Employee:
    def __init__(self,name,code):
        self.__name=name
        self.__code=code
    def set_name(self,name):
        self.__name=name
    def set_code(self,code):
        self.__code=code
    def get_name(self):
        return self.__name
    def get_code(self):
        return self.__code