m=int(input())
n=input()
char=''
num=0
while m>0:
    if m%16>=0 and m%16<=9: 
        char=str(m%16)+char
    else:
        char=chr(m%16+55)+char
    m=m//16
for i in char:
    if '0'<=n<='9' and n==i:
        num+=1
    elif n.upper()==i or n==i:
        num+=1
print(num)