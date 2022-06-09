long=int(input())
n=10**(long-1)
m=10**long-1
flag=True
for i in range(n,m+1):
    flag=True
    if i//10**(long-1)!=(i//10**(long-2))%10:
        flag=False
    if (i%10)%2!=1:
        flag=False
    if (i//10)%10+i%10!=5:
        flag=False
    if i%3!=0:
        flag=False
    if flag==True:
        print(i)