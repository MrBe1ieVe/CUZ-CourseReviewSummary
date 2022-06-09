a,b=map(int,input().split())
flag=True
result=0
while flag:
    result=result+(abs(a)%10)*(abs(b)%10)
    a=abs(a)//10
    b=abs(b)//10
    if a==0 and b==0:
      break
print(result)