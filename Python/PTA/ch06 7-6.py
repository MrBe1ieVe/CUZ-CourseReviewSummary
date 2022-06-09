n=int(input())
true=0
false=0
for i in range(n):
    a=list(input().split())
    if len(list(a))==len(set(a)):
        false +=1
    else:
        true +=1
print('True=%d, False=%d'%(true,false))