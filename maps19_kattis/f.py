import math
pi = math.acos (-1)

def main ():
    t = int (input ())
    for i in range (0, t):
        inp = input ().split (' ')
        ans = 0
        ans += pi * (int (inp [0]) ** 2)
        new = 4
        for j in range (1, int (inp [1])):
            ans += new * ((int (inp [0]) / (2 ** j)) ** 2) * pi
            new *= 3
        print (ans)

if __name__ == '__main__':
    main ()
