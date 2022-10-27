def NOD(num1, num2):
    while num1 != 0 and num2 != 0:
        if num1 >= num2:
            num1 %= num2
        else:
            num2 %= num1
    out_blue("__________")
    print(num1 or num2)
    out_blue("__________")

def simpleDividers(n):
   answer = []
   d = 2
   while d * d <= n:
       if n % d == 0:
           answer.append(d)
           n //= d
       else:
           d += 1
   if n > 1:
       answer.append(n)
   print (answer)

def out_blue(text):
    print("\033[31m\033[43m".format(text))
def init(*args):
    i = 0
    lens = len(args)
    while(i+2 <= len(args)):
        num1 = args[i]
        num2 = args[i + 1]
        NOD(num1, num2)
        simpleDividers(num1)
        simpleDividers(num2)
        i += 2