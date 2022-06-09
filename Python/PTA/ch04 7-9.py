m=int(input())
result=0
l=len(str(m))
fir=(m//10**(l-1)+8)%7
two=(m//1000%10+8)%7
thi=(m//100%10+8)%7
four=(m//10%10+8)%7
five=(m%10+8)%7
result=five*10000+thi*1000+two*100+four*10+fir
print(result)
      