char=input()
num=0
num2=0
string=''
former_list=['']*26
change_list=['']*26
for i in range(26):
    former_list[num]=chr(i+65)
    num=num+1
for i in range(26,0,-1):
    change_list[num2]=chr(i+65)
    num2=num2+1
for j in char:
    if j in former_list:
        string=string+change_list[ord(j)-64]
    else:
        string=string+j
print(string)

    