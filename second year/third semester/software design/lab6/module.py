def NOD(*args):
    for x in range(len(args) - 2):
         a=args[x]
         b=args[x+1]
         while a != 0 and b != 0:
             if a > b:
                 print(a)
                 a %= b
             else:
                 print(b)
                 b %= a
             if a > 0:
                b=args[x+2]
                d=a+b
                while d != 0 and a != 0:
                    if d > a:
                        d %= a
                        print(d)
                    else:
                        a %= d
                        print(a)
                return d+a
             else:
                a=args[x+2]
                d=a+b
                while d != 0 and b != 0:
                    if d > b:
                        d %= b
                        print(d)
                    else:
                        b %= d
                        print(b)
                return d+b
def Print(a,b,c):
    print("result: " + str(NOD(a,b,c)))