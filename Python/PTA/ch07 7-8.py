m=set(input())
n=set(input())
flag=True
if len(m)==len(n):
    for i in m:
        if i in n:
            n=n-{i}
            m=m-{i}
    for j in n:
        if j in m:
            n=n-{j}
            m=n-{j}
if len(m)==0 and len(n)==0:
    print('yes')
else:
    print('no')