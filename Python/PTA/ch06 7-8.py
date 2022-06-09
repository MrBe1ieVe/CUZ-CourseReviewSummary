s=input()
su=0
n=0
for i in range(len(s)):
    if s[i]=='[':
        n+=1
    elif s[i]==']':
        n-=1
    elif s[i]==',':
        continue
    elif s[i+1]==',' or s[i+1]==']':
        su += n
print(su)