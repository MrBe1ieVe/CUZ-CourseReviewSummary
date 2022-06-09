m=list(map(int,input().split(",")))
a=[1,2,3,4,5,6,7,8,9,10]
flag=[0,0,0,0,0,0,0,0,0,0]
char=''
for i in m:
    if m[i]>=1 and i<=10:
        flag[int(i-1)]=1
for j in range(5,10):
    if flag[j]==0:
        char=char+str(j+1)+' '
print(char.rstrip())