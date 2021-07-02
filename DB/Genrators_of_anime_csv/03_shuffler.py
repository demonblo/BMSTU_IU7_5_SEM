from random import *

n = open('names.csv', 'r')
t = open('titles.csv', 'r')
r = open('roles.csv', 'w')

names = []
titles = []
roles = ["Drawer", "Scenarist", "Seyu", "Director"]

counter = 1
line_n = n.readline()
names.append(counter)
counter+=1
while line_n:
    line_n = n.readline()
    names.append(counter)
    counter+=1

counter = 1
line_t = t.readline()
titles.append(counter)
counter+=1
while line_t:
    line_t = t.readline()
    titles.append(counter)
    counter+=1

n.close()
t.close()

for i in range(len(names) - 2):
    kek = randint(0, len(names) - 2 - i)
    cur = names[kek]
    names[kek] = names[len(names) - 2]
    names[len(names) - 2] = cur

for i in range(len(titles) - 2):
    kek = randint(0, len(titles) - 2 - i)
    cur = titles[kek]
    titles[kek] = titles[len(titles) - 2]
    titles[len(titles) - 2] = cur

for i in range(len(names) - 1):
     new_line = ""
     lol = randint(0, 3)
     if (names[i] == 12295):
         names[i] = 12294
     new_line += str(titles[i]) + ',' + str(names[i]) + ',' + roles[lol] + '\n'
     r.write(new_line)

r.close()
