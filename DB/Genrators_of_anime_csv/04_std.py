from random import *

f = open("first.txt", 'r')
fir = []
s = open("second.txt", 'r')
sec = []
st = open("studios.csv", 'w')

line = f.readline()
fir.append(line)
while line:
    line = f.readline()
    fir.append(line)

line = s.readline()
sec.append(line)
while line:
    line = s.readline()
    sec.append(line)
kek = 0
lol = 0
for i in range(1000):
    new_line = ""
    new_line += fir[kek]
    new_line = new_line + ' ' + sec[lol]
    final_line = ""
    for j in new_line:
        if (j != '\n'):
            final_line += j

    final_line += '\n'
    st.write(final_line)
    if (lol == 32):
        kek += 1
        lol = 0
    else:
        lol += 1
            

f.close()
s.close()
st.close()
    
    

