
def eng_and_chi(m):
    word=0
    for i in char:
        if '\u4e00'<=i<='\u9fff' or 'a'<=i<='z' or 'A'<=i<='Z':
            word=word+1
    return word
def space(char):
    space=0
    for i in char:
        if ord(i)==32:
            space += 1
    return space
def number(char):
    num=0
    for i in char:
        if ord(i)>=48 and ord(i)<=57:
            num += 1
    return num
def others(char):
    other=0
    other=len(char)-eng_and_chi(char)-space(char)-number(char)
    return other
char=input()
print(eng_and_chi(char),end=' ')
print(space(char),end=' ')
print(number(char),end=' ')
print(others(char),end='')