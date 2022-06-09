m=int(input())
char='['
for i in range(1,m):
    if m%i==0:
        char=char+str(i)+','+' '
char=char+str(m)+']'
print(char)