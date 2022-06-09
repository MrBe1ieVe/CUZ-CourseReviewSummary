use,extra=map(float,input().split())
fee=0
if use<=50:
      fee=use*0.53
      print("cost = ",end='')
      print(format(fee,'.2f'))
else:
      fee=50*0.53+(use-50)*(extra+0.53)
      print('cost = ',end='')
      print(format(fee,'.2f'))