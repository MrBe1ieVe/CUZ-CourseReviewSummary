year=int(input())
if year%4==0 and year%100!=0:
    print(year,end='')
    print("是闰年")
elif year%400==0:
    print(year,end='')
    print("是闰年")
else:
    print(year,end='')
    print("不是闰年")