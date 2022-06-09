N=input()
number=len(N)
N=int(N)
b=0
for i in range(1,number+1):
       b=b+N%10
       N=N//10
print(number,end=' ')
print(b)