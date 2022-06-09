m=int(input())
for i in range(0,m):
    try:
        math=input()
        result=eval(math)
        print('{:.2f}'.format(result))
    except NameError:
        print('NameError')
    except ZeroDivisionError:
        print('ZeroDivisionError')
    except SyntaxError:
        print('SyntaxError')
    