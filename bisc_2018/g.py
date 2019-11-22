import math

n, k = input ().split (' ')

arr = list (range (1, int (n) + 1))

#print (arr)

ans = []

def f (x):
    if len (arr) == 0:
        return
    fat = math.factorial (len (arr) - 1)
    print (arr [int (x) // fat], end = ' ')
    del arr [int (x) // fat]
    f (int (x) % fat)

f (int (k) - 1)
