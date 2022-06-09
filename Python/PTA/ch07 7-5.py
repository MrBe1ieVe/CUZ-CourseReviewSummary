a=input()
m=input()
b=input()
d1={0:0}
d2={0:0}
flag=True
d1[0]=int(a)
d2[0]=int(b)
result=0
if int(b)==0:
    flag=False
if m=='+' and flag==True:
    result=d1.get(0,0)+d2.get(0,0)
if m=='-':
    result=d1.get(0,0)-d2.get(0,0)
if m=='*' and flag==True:
    result=d1.get(0,0)*d2.get(0,0)
if m=='/' and flag==True:
    result=d1.get(0,0)/d2.get(0,0)
if flag:
    print('{:.2f}'.format(result))
else:
    print("divided by zero")