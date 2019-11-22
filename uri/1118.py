arr = []

while True:
  while len (arr) < 2:
    x = float (input ())
    if (x >= 0.0 and x <= 10.0):
      arr.append (x)
    else:
      print ('nota invalida')

  print ('media = %.2f' % ((arr [0] + arr [1]) / 2.0))
  del arr [:]
  x = 0
  while (x < 1) or (x > 2):
    print ('novo calculo (1-sim 2-nao)')
    x = int (input ())
  if x == 1:
    continue
  else:
    break
