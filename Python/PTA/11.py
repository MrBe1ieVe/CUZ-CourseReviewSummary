s = input()
l = s.split()
chdu = len(l)
sum = 0
for i in range(chdu):
  sum = sum + float(l[i])
print(chdu)
print("{:.3f}".format(sum))