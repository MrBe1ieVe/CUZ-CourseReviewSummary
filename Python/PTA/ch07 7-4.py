s1=eval(input())
s2=eval(input())
list_dig=[]
list_wor=[]
dic={}
num=0
for i in s1:
    dic[i]=dic.get(i,0)+s1.get(i,0)
    if type(i)==type(1):
        list_dig.append(i)
    elif type(i)==type('a'):
        list_wor.append(i)
for i in s2:
    dic[i] = dic.get(i, 0) + s2.get(i, 0)
    if type(i)==type(1):
        list_dig.append(i)
    elif type(i)==type('a'):
        list_wor.append(i)
list_dig.sort()
list_wor.sort()
list=list_dig+list_wor
print("{",end="")
l=len(dic)
for i in list:
    if i in dic:
        num += 1
        if type(i)==type(1):
            print("{}:{}".format(i,dic[i]),end="")
        else:
            print('"{}":{}'.format(i,dic[i]),end="")
        del dic[i]
        if num!=l:
            print(",",end="")
print("}")