d1=eval(input())
d2=eval(input())
d3={}
for i in d1:
    d3[i]=d1[i]+d2.get(i,0)
for i in d2:
    if i not in d3.keys():
        d3[i]=d2[i]
d3=dict(sorted(d3.items(),key=lambda x:x[0] if type(x[0])==int else ord(x[0])))
cnt=0
print('{',end='')
for i in d3:
    if type(i)==str:
        print('"{}":{}'.format(i,d3[i]),end='')
    else:
        print('{}:{}'.format(i,d3[i]),end='')
    cnt+=1
    if cnt!=len(d3):
        print(',',end='')
print('}',end='')