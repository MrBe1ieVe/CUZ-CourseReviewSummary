weight,s=map(float,input().split())
fee=0
if   s>=3000:
      fee=s*0.85*weight
      print(int(fee))
elif s>=2000:
      fee=s*0.90*weight
      print(int(fee))
elif s>=1000:
      fee=s*0.92*weight
      print(int(fee))
elif s>=500:
      fee=s*0.95*weight
      print(int(fee))
elif s>=250:
      fee=s*0.98*weight
      print(int(fee))
elif s>=0:
      fee=s*weight
      print(int(fee))
