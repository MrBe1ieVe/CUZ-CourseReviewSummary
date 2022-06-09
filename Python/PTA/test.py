N=int(input())
average=0
result=0
c=0
char=''
i=1
flag=True
while i<=N:
    try:
        grades=input()
        grades=grades.strip()
        result=result+int(grades)
        c=c+1
        i=i+1
    except:
        char=char+grades
        flag=False
if flag==True:
    print('All OK')
else:    
    for j in char:
        print('Error for data',j+'! Reinput')
average=result/c
print('avg grade = ',end='')
print('{:.2f}'.format(average))

