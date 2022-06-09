def hws(num):
    tmp=num
    result=0
    while tmp>0:
        result=result*10+tmp%10
        tmp //= 10
    if result==num or num<10:
            return True
    else:
            return False
n=int(input())
for i in range(0,n+1):
    if hws(i):
        print(i)