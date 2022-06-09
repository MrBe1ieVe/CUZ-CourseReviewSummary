a=dict(eval(input()))
b=dict(eval(input()))
for i in b:
    if i not in a:
        a[i]=b[i]
    else:
        a[i]+=b[i]
print("{",end="")
s1=[i for i in a.keys() if type(i)==type(1)]
s2=[i for i in a.keys() if type(i)==type('a')]
s1.sort()
s2.sort()
c=0
n=len(a)
for i in s1+s2:
    c+=1
    if type(i)==type(1):
        print("{}:{}".format(i,a[i]),end='')
    else:
        print('"{}":{}'.format(i,a[i]),end='')
    if c!=n:
        print(',',end='')
print("}")