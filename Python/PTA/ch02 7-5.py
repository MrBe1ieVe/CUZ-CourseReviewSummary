x=float(input())
if x==0:
    print("g(0.000)=0.000")
else:
    result=0.5/x
    print("g(",format(x,',.3f'),') = ',format(result,',.3f'),sep='')