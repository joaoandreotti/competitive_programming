import sys, math
n = input ()

'''
def prime (a):
  for i in range (2, int(math.sqrt (a))):
    if (a % i == 0):
      return False
  return True

ans = 0
count = 0
i = 2
while i < math.sqrt (n):
  if (prime(i)):
    if (count == 1):
      ans += 1
    if (aux % i == 0):
      aux /= i
      count += 1
      continue
  count = 0
  i += 1
'''
ms = {1}
def factors (n):
  x = 2
  while (x * x) <= n:
    while (n % x == 0):
      ms.add (x)
      n /= x
    x += 1
  if n > 1:
    ms.add (n)

factors (n)
ans = len (ms) - 1

ans = int(math.pow (2, ans) - (ans + 1))

print (str(ans))
