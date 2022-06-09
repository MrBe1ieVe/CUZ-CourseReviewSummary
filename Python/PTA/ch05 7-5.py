n=int(input())
l=0
d=0
result=0
ave=0
flag=True
try:
    for i in range(n):
        m=input()
        l=float(m)
        result=result+l
        d=d+1
    ave=result/d
    print('正确')
    print('avg=',end='')
    print('{:.2f}'.format(ave))
except ValueError:
    print('数值错误')
except ZeroDivisionError:
    flag=False
    print('除0错误，n不能等0')
finally:
    print('程序结束')