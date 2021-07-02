from random import *

j = open('names.csv', 'w')

for i in range(7000):
    n = open('names.txt', 'r')
    s = open('surnames.txt', 'r')
    new_line = ""
    kek = randint(1, 100000)
    for l in range(kek):
        name_line = n.readline()
    kek = randint(1, 90000)
    for l in range(kek):
        surname_line = s.readline()

    for k in name_line:
        if (k != '\n'):
            new_line += k
    new_line += ' '
    for k in surname_line:
        if (k != '\n'):
            new_line += k
    new_line +=','
    kek = '1'
    new_line += kek
    new_line += '\n'
    j.write(new_line)
    n.close()
    s.close()
j.close()
    
