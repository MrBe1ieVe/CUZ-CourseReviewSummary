N=int(input())
i=1
falg=True
wrong=0
true=0
while i<=N:
    try:
        grades=input()
        temp=grades
        grades=grades.strip()
        c=eval(grades)
        if type(c)==int:
            result=result+int(grades)
            c=c+1
            i=i+1
            true=true+1
    except:
        print('line',i,'error for input','"',temp,'"')
        wrong=wrong+1
ave=result/c
print('Total:',N)
print('OK:',true)
print('Error:',wrong)
print('avg grade =',ave)