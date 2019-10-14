def b(x=10,y=1):
    if x == 0:
        print(y)
        return 0
    elif x == 1:
        print(y)
        return 1
    else:
        return b(x-1)+b(x-2)
print(b(),b(20))
