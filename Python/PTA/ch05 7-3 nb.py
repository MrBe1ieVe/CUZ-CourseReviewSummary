n=int(input())
sum=0
flag=0
temp=n
count=0
count1=0
l=[]
while True:
    try:
        l.append(input())
    except:
        break
for i in range(len(l)):
    count+=1
    a=0
    a=l[i]
    try:
        a=int(a)
        sum=sum+a
        count1+=1
    except:
        print('line {} error for input "{}"'.format(count,a))
        flag+=1
if flag==0:
       print("All OK")
if count<n:
    print("end of files")
print("Total: {}".format(len(l)))
print("OK: {}".format(count1))
print("Error: {}".format(flag))
print("avg grade = {:.2f}".format(sum/count1))