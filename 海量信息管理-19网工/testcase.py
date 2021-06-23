str0=input()
str1=input()
mylist=[]
for ch in str0:
    mylist.append(ch)
temp=""
newlist=[]
for ch in mylist:
    if ch != str1:
        temp+=ch
    else:
        newlist.append(temp)
        temp=""
newlist.append(temp)    
print(newlist)
