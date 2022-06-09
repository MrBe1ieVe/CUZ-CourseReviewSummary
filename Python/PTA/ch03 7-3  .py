a,b=map(int,input().split())
al=0
bl=0
c=0
result=0
max=0
if a>=b:
    max=len(str(a))
else:
    max=len(str(b))
for i in range(1,max+1):
      while (a//10>=b):
          result=result+a%10
          a=a//10
      al=a%10
      bl=b%10
      c=al*bl
      result=result+c
      a=a//10
      b=b//10
print(result)
