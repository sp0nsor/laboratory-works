from asyncore import write
import random

f1 = open("sort500.txt", "w")

i = 0
n = 500

while (i < n):
    f1.write(str(i) + " ")
    i+= 1

f1.close()

#--------

f2 = open("sort5000.txt" , "w")

i = 0
n = 5000

while (i < n):
    f2.write(str(i) + " ")
    i += 1

f2.close()

#---------

f3 = open("sort50000.txt", "w")

i = 0
n = 50000

while(i<n):
    f3.write(str(i) + " ")
    i += 1

f3.close()

#---------

f4 = open("reverse500.txt", "w")

i = 0
n = 500

while(n > i):
    f4.write(str(n) + " ")
    n -= 1

f4.close()

#---------

f5 = open("reverse5000.txt", "w")

i = 0
n = 5000

while(n > i):
    f5.write(str(n) + " ")
    n -= 1

f5.close()

#---------

f6 = open("reverse50000.txt", "w")

i = 0
n = 50000

while(n > i):
    f6.write(str(n) + " ")
    n -= 1

f6.close()

#---------

f7 = open("rand500.txt", "w")

i = 0
n = 500

while(i < n):
    zxc = random.randint(0, 50000)
    f7.write(str(zxc) + " ")
    i += 1

f7.close()

#---------

f8 = open("rand5000.txt", "w")

i = 0
n = 5000

while(i < n):
    zxc = random.randint(0, 50000)
    f8.write(str(zxc) + " ")
    i += 1

f8.close()

#---------

f9 = open("rand50000.txt", "w")

i = 0
n = 50000

while(i < n):
    zxc = random.randint(0, 50000)
    f9.write(str(zxc) + " ")
    i += 1

f9.close()