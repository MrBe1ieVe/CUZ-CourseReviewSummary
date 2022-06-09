import random
char_list=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'0','1','2','3','4','5','6','7','8','9']
num=0
char=''
x=int(input())
n=int(input())
m=int(input())
random.seed(x)
for i in range(n):
    for j in range(m):
        place=random.randrange(62)
        char=char+char_list[place]
    print(char)
    char=''