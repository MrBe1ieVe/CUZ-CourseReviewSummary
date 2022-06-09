m=int(input())
flag=False
l=0
c=0
def back(m):  #判断
    for i in range(0,m+1):
        if i<=9:
            flag=True
            print(i)
        else:
            wid=len(str(i))
            flag=deep(i,wid)
            if flag==True:
                print(i)
    return flag
def deep(n,k): #判断大于10的数
    l=k
    c=n
    while n>=9:
        flag=False
        left=n//10**(l-1) #最左边
        right=n%10        #最右边
        if left==right:
            flag=True
            n=(n-left*10**(l-1)-right)/10
            l=len(str(n))
        else:
            flag=False
            break
    return flag    #返回
back(m)