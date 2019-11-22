import datetime
import calendar

dic = { 'January' : 1, 'February' : 2, 'March' : 3, 'April' : 4, 'May' : 5, 'June' : 6, 'July' : 7, 'August' : 8, 'September' : 9, 'October' : 10, 'November' : 11, 'December' : 12 }

while True:
    try:
        a, b, c = input ().split (' ')
        print (datetime.date (int (c) % 28, dic [b], int (a)).strftime ("%A"))
    except:
        break
