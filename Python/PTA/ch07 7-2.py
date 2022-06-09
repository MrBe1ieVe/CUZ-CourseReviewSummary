str1=input().strip()
c=input().strip()
char=''
flag=[0]*len(str1)
for i in range(len(str1)):
    if c==str1[i] or c==str1[i].upper() or c==str1[i].lower():
        flag[i]=1
for j in range(len(str1)):
    if flag[j]==0:
        char+=str1[j]
print('result:',char)