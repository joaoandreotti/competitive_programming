def oddp (n):
  x = 1
  i = 0
  while (i <= n):
    s = str (x)
    rs = ""
    for k in range (0, len (s)):
      rs += s [len (s) - k - 1]
    if (s == rs):
      print ("palindrome (" + str (i) + ") : " + s)
      i += 1
    x += 2

oddp (609)

def cnt (n):
  i = 1
  x = 10 ** i
  f = 5
  while (i <= n):
    if (i >= 2):
      i -= 2
      x = 10 ** ((i + 1)// 2)
      print (str (f * x))
      i += 2
    else:
      x = 10 ** (i// 2)
      print (str (f * x))

    i += 1


cnt (20)

print ("_-----------------------------_")

def nump (n):
  x = 0
  i = 0
  while (i <= n):
    s = str (x)
    rs = ""
    for k in range (0, len (s)):
      rs += s [len (s) - k - 1]
    if (s == rs):
      print ("palindrome (" + str (i) + ") : " + s)
      i += 1
    x += 1

nump (100)

def numcnt (n):
  i = 1
  x = 10 ** i
  f = 10
  while (i <= n):
    if (i >= 2):
      i -= 2
      x = 10 ** ((i + 1)// 2)
      print (str (f * x))
      i += 2
    else:
      x = 10 ** (i// 2)
      print (str (f * x))

    i += 1

numcnt (20)

####################################################

def rec (c, p):
  if (c <= 0):
    return ""
  i = 0
  count = lst_even_p [c] // 10
  ponta = p % count
  print ("c: " + str (c) + ", p: " + str (p))
  print ("count: " + str (count) + ", ponta: " + str (ponta))
  return str (ponta) + rec (c - 2, p // count)


lst_odd_p = [5, 5, 50, 50, 500, 500, 5000, 5000, 50000, 50000, 500000, 500000, 5000000, 5000000, 50000000, 50000000, 500000000, 500000000, 5000000000, 5000000000, 50000000000, 50000000000, 500000000000, 500000000000]
lst_even_p = [10, 10, 100, 100, 1000, 1000, 10000, 10000, 100000, 100000, 1000000, 1000000, 10000000, 10000000, 100000000, 100000000, 1000000000, 1000000000, 10000000000, 10000000000, 100000000000, 100000000000, 1000000000000, 1000000000000]
lst = [1, 3, 5, 7, 9]
pos = int (input ())
postmp = pos
chars = 0
edge = 0

i = 0
while (postmp - lst_odd_p [i] >= 0):
  postmp -= lst_odd_p [i]
  i += 1
chars = i

i = 0
while (postmp - lst_even_p [i] >= 0):
  postmp -= lst_even_p [i]
  i += 1
edge = i


print ("postmp: " + str (postmp))

if (chars > 1):
  print ("ponta num: " + str (lst [edge]) + ("x" * (chars - 1)) + str (lst [edge]))
else:
  print ("ponta num: " + str (lst [edge]))


print (str (lst [edge]) + rec (chars, postmp))
