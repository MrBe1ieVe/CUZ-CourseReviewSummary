a=input()
b=input()
j=1
flag=False
for i in a:
    if i==b:
        flag=True
        break
    else:
        j += 1
if flag:
    print('index=',end='')
    print(str(j))
else:
    print("can't find letter",b)