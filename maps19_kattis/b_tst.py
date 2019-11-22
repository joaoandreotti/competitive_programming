arr = []

for i in range (0, int (1e6 + 1)):
    arr.append (0)

def fk (n, k):
    if (arr [n] != 0):
        return arr [n]
    if n == 1:
        arr [n] = 42
        return arr [n]
    elif n == 2:
        arr [n] = (11 * k) + 77
        return arr [n]
    arr [n] = (2 * fk (n - 1, k)) - fk (n - 2, k) + (10 * k)
    return arr [n]
       
print (fk (1000000, 100))
