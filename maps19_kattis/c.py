ans_set = []
def func (s, digs, lst, x = ''):
    #print ('lst: ' + str (lst))
    if lst == []:
        #print ('exit')
        return
    if len (s) == len (x) - 1:
        #print ('gen: ' + x [0:len (x) - 1])
        return

    #print ('x: ' + x)
    aux1 = x + lst [0]
    aux2 = x + lst [0]
    if len (x) < (len (s)):
        aux1 += '+'
        aux2 += 'x'
        func (s, digs, lst [1:len (lst)], aux1)
        func (s, digs, lst [1:len (lst)], aux2)
    if len (s) == len (aux1) - 1:
        ans = ''
        for c in aux1:
            if c != 'x':
                ans += c
        if ans [len (ans) - 1] == '+' or ans [len (ans) - 1] == 'x':
            ans = ans [:-1]
        #print (str (ans))
        #solve the equation
        ans = ans.split ('+')
        t_sum = 0
        for c in ans:
            t_sum += int (c)
        ans_set.append (t_sum)
        

def main ():
    s = str (input ())
    digs = s.split ('+')
    func (s, digs, digs)
    ans_set.sort ()
    count = 1
    i = 0
    last = ans_set [0]
    for x in ans_set:
        if i > 0:
            if x != last:
                count += 1
        last = x
        i += 1
    print (count)

main ()
