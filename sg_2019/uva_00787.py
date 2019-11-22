import fileinput

def f (arr):
  arr = arr.split (' ')
  mn = int (arr [0])
  mx = int (arr [0])
  ans = int (arr [0])
#  print ('mn: ' + str (mn))
#  print ('mx: ' + str (mx))
#  print ('ans: ' + str (ans))
#  print ('-------')
  count = 0
  for i in arr:
    i = int (i)
    if i == -999999:
      break
    if count > 0:
      if i > 0:
        mx = max (i, mx * i)
        mn = min (i, mn * i)
      else:
        x = max (mn * i, i)
        mn = min (mx * i, i)
        mx = x
      ans = max (ans, mx)
    count += 1
  return ans

def main ():
  for x in fileinput.input ():
    print (str (f (x)))
#    print ('--')

if __name__ == '__main__':
  main ()
