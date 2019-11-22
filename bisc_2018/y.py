a = 0
b = 1
c = 1

n = int (input ())

lst = []

if n == 0:
    print (a)
elif n == 1:
    print (b)
elif n == 2:
    print (c)
else:
    lst.append (a)
    lst.append (b)
    lst.append (c)
    for i in range (3, n + 1):
        a = a + c
        b = a + b
        c = b + c
        lst.append (a)
        lst.append (b)
        lst.append (c)
    print (lst [n])
