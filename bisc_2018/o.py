import math

a = input ()
a = int (a)

arr = list (range (1, a + 1))

lcm = 0
for i in range (1, a + 1):
    if i == 1:
        lcm = i
    else:
        lcm = (lcm * i) // math.gcd (i, lcm)

print (lcm)
