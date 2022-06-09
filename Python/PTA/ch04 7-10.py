num=int(input())
def kaozla(num):
    char=''
    while num!=2:
        if num%2==1:
            num=num*3+1
        elif num%2==0:
            num=int(num/2)
        char=char+str(num)+','
    char=char+'1'
    return char
print(kaozla(num))