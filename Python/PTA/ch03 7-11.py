c,d=map(int,input().split(','))
for i in range(max(c,d),c*d+1,max(c,d)):
    if i%min(c,d)==0:
        b=i
        break
for i in range(min(c,d),1,-1):
    if c%i==0 and d%i==0:
        a=i
        break
print('GCD:',a,', LCM:',b,sep='')