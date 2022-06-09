n=int(input())
m=2
num=0
clist=[0]*n
blist=[0]*n
alist=[1]*n
for x in range(n):
    blist[x]=x
for i in range(3,n//2+1):
    for j in range(2,i):
        if i%j==0 and alist[i]==1:
            alist[i]=0
        while i*m<n:
            alist[i*m]=0
            m=m+1
        m=2     
alist[0]=0
alist[1]=0
for a in range(n):
    if alist[a]==1:
        clist[num]=blist[a]
        num=num+1
dlist=[0]*num
dlist=clist[0:num]
print(dlist)