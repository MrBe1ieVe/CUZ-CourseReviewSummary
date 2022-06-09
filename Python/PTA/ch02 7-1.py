command,match,accord=input().split()
command=int(command)
accord=int(accord)
result=0
if match=="*":
  result=command*accord
  print(str(command)+
               match+
               str(accord)+
               '='+
               str(result))
if match=="//":
  result=command//accord
  print(str(command)+
        match+
        str(accord)+
        '='+
        str(result))
if match=="%":
  result=command%accord
  print(str(command)+
        match+
        str(accord)+
        '='+
        str(result))
elif result==0:
  print("Invalid operator")