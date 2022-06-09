a=input()
s1=''
num=0;result=0
for i in a:
    if i>='0' and i<='9':
        s1=s1+i
    elif 'a'<=i<='f' or 'A'<=i<='F':
        s1=s1+i
s2=s1
s1=s1.upper()
for i in range(len(s1),0,-1):
    if s1[i-1]>='0' and s1[i-1]<='9':
        result=result+int(s1[i-1])*16**(num)
    else:
        result=result+(ord(s1[i-1])-55)*16**(num)
    num+=1
print(s2)
print(result)