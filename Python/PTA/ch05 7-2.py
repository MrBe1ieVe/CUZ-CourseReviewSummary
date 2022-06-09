row = 0
n = int(input())
cnt = 0
s = 0
level = 0
for i in range(n):
    try:
        l = input()
    except:
        break
    row = row + 1
    try:
        l = int(l)
        s += l
        cnt += 1
    except:
        level += 1
        print('line {} error for input "{}"'.format(row,l))
        continue
if row < n :
    print("end of files")
print('Total: %d'%row)
print('OK: %d'%cnt)
print('Error: %d'%level)
print('avg grade = {:.2f}'.format(s/cnt))
