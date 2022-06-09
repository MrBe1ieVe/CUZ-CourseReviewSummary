def prime(n):                           #判断质数
    import math
    if n==1:
        return 0
    k=math.floor(n**(1/2))
    for i in range(2,k+1):
        if n%i==0:
            return 0
    return 1


def zhao(n):
    if n <= 0:
        print(3,5)
        return 0
    for i in range(n+1,99999999999):
        if prime(i)==1 and prime(i+2)==1:
            print(i,i+2)
            return 0
    return 0

zhao(int(input()))