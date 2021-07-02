from random import *
f = open('title.csv', 'r')
j = open('new_title.csv', 'w')
line = f.readline()
new_line = ""
flag = 0
for i in line:
    if (flag == 1):
        new_line += i
    if (flag == 0 and i == ','):
        flag = 1
j.write(new_line)
while line:
    line = f.readline()
    new_line = ""
    flag = 0
    for i in line:
        if (flag == 1):
            new_line += i
        if (flag == 0 and i == ','):
            flag = 1
    j.write(new_line)
f.close()
j.close()

k = open('new_title.csv', 'r')
a = open('final_title.csv', 'w')
line = k.readline()
new_line = ""
flag = 0
for i in reversed(line):
    if (flag == 2):
        new_line += i
    if (flag == 1 and i == ','):
        flag = 2
    if (flag == 0 and i == ','):
        flag = 1
new_line+= '\n'
a.write(new_line)
while line:
    line = k.readline()
    new_line = ""
    flag = 0
    for i in reversed(line):
        if (flag == 2):
            new_line += i
        if (flag == 1 and i == ','):
            flag = 2
        if (flag == 0 and i == ','):
            flag = 1
    new_line+= '\n'
    a.write(new_line)
k.close()
a.close()

b = open('final_title.csv', 'r')
c = open('titles.csv', 'w')
line = b.readline()
new_line = ""

for i in reversed(line):
    if (i != '\n'):
        new_line += i
        
kek = randint(1, 1000)
kek = str(kek)
new_line = new_line + ',' + kek + '\n'
c.write(new_line)
while line:
    line = b.readline()
    new_line = ""
    for i in reversed(line):
        if (i != '\n'):
            new_line += i
    kek = randint(1, 1000)
    kek = str(kek)
    new_line = new_line + ',' + kek + '\n'
    c.write(new_line)
b.close()
c.close()
