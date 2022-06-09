a = input()
try:
    b = eval(a)
    if type(b) == int:
        print("yes")
    elif type(b) == float:
        print("yes")
    elif type(b) == complex:
        print("yes")
    else:
        print("no")
except:
    print("no")
 

        