import math
a=int(input())
b=int(input())
c=int(input())
p=0
s=0
def tangle(a,b,c):
    flag=True
    if a+b>c and b+c>a and a+c>b:
        flag=True
    else:
        flag=False
    if a<0 or b<0 or c<0:
        flag=False
    return flag
if tangle(a,b,c):
    p=(a+b+c)/2
    s=math.sqrt(p*(p-a)*(p-b)*(p-c))
    print('{:.2f}'.format(s))
else:
    print("数据错误")