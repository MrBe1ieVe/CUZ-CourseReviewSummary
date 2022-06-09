alist=list(input().split())
blist=list(input().split())
num=0
char=''
if len(alist)>len(blist):
    max=len(alist)
    min=len(blist)
else:
    max=len(blist)
    min=len(alist)
for i in range(max):
    if alist[i] in blist:
        continue
    else:
        print(alist[i],end=' ')
for j in range(min):
    if blist[j] in alist:
        continue
    else:
        char=char+blist[j]+' '
char=char.rstrip()
print(char,end='')