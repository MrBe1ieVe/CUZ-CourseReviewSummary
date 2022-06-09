n=int(input())
ave=0
result=0
numbers=[]
numbers=list(map(int,input().split()))
numbers.sort()
del numbers[0]
del numbers[n-2]
ave=(sum(numbers)-min(numbers)-max(numbers))/(n-4)
print('aver=',end='')
print('{:.2f}'.format(ave))