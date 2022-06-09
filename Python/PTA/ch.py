command,match,accord=input().split()
command=int(command)
accord=int(accord)
result=command*accord
if match!="*" and match!="//" and match!="%":
       print("Invaild operator")
else:
       print(str(command)+
             match+
             str(accord)+
             '='+
             str(result))
