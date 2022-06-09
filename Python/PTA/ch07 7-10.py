a=input()
ma=''
num=0
for i in a:
    num+=1
    if i>=ma:
        ma=i
        place=num
print(ma+'   '+str(place-1))
