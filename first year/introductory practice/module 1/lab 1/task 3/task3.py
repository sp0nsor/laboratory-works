import math

tmp = int(input("введите число > "))

res = ((tmp//10)%10)*100+(tmp//100)*10+tmp%10

print (res)