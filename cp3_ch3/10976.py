import sys
n = sys.stdin.read ()

count = 0
int_list = []
int_list.append (0)

for k in n:
  if k != '\n':
    int_list [count] *= 10
    int_list [count] += float (k)
  else:
    int_list.append (0)
    count += 1

print (int_list)


for k in int_list:
  if k == 0:
    break
  
  count = 0
  for i in range (int (k) + 1, (2 * int (k)) + 1):
    y = (k * i) / (k - i)
    if ((1/y) + (1/i)) == (1/k):
      count += 1

  print (k)
  for i in range (int (k) + 1, (2 * int (k)) + 1):
    y = (k * i) / (k - i)
    if ((1/y) + (1/i)) == (1/k):
      print ('1/%f = 1/%f + 1/%f', k, y, i)

