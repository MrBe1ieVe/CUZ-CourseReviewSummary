import math
mis=float(input())
maxn=100000
result=0
q=0
end=0
for i in range(1,maxn):
     result=result+1/(i*i)
     i=i+1
     if 1/(i*i)<mis:
         q=result*6
         end=math.sqrt(q)
         break   
print('{:.6f}'.format(end))