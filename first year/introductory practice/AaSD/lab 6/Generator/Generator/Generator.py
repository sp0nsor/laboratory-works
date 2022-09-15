import random

f1 = open("sort1000.txt", "w")

i = 1
n = 1000

while (i<=n):
    f1.write(str(i)+ "\n")
    i += 1

f1.close()

#------------------

f2 = open("sort10000.txt", "w")

i = 1
n = 10000

while (i < n):
    f2.write(str(i) + "\n")
    i+=1

f2.close

#------------------

f3 = open("sort1000000.txt", "w")

i = 1
n = 1000000

while (i <= n):
    f3.write(str(i) + "\n")
    i+=1

f3.close()

#------------------

f4 = open("sort1000negative.txt", "w")

i = 1
n = 1000

while (n >=i):
    f4.write (str(n) + "\n")
    n-=1

f4.close()

#------------------

f5 = open("sort10000negative.txt", "w")

i = 1
n = 10000

while (n>=i):
    f5.write(str(n) + "\n")
    n -= 1

f5.close()

#------------------

f6 = open("sort1000000negative.txt", "w")

i = 1
n = 1000000

while (n >= i):
    f6.write(str(n) + "\n")
    n -= 1

f6.close()

#------------------

f7 = open("rand1000.txt", "w" )

i = 1
n = 1000

while (i<=n):
    b = random.randint(1, 1000)
    f7.write(str(b) + "\n")
    i += 1

f7.close()

#------------------

f8 = open("rand10000.txt", "w")

i = 1
n = 10000

while (i <= n):
    b = random.randint(1, 10000)
    f8.write(str(b) + "\n")
    i += 1

f8.close()

#------------------

f9 = open("rand1000000.txt", "w")

i = 1
n = 1000000

while (i <= n):
    b = random.randint(1, 100000)
    f9.write(str(b) + "\n")
    i += 1

f9.close()

