N=input()
mid=input()
l=len(N)
d=0
m=-1
try:
    d=int(mid)
    for i in N:
        m=m+1
        if m==int(mid):
            print(i)
            break
        if l<int(mid):
            print('下标越界')
            break
except:
    print('下标要整数')
