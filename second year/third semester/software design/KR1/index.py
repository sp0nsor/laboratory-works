def f1 (a, b):
    for index in range (a, b):
        if ((index - 5) % 7) == 0:
            print(index)

print ("-------------------------------")
a = int(input("Enter a = "))
b = int(input("Enter b = "))
print(f1(a,b))


def f2(*list):
    size = len(list)
    C = 0.0
    for index in list:
        C += (index * index * index) / size
    return(C * C * C)

print ("-------------------------------")
list = [3, 1, 7, 10, 12, 4]
print (f2(*list))
print ("-------------------------------")

def f3 (*list):
    size = len(list)
    H = 0.0
    for index in list:
        H += 1/(size * index)
    return H

print ("-------------------------------")
list = [3, 1, 7, 10, 12, 4]
print (f3(*list))
print ("-------------------------------")

def f4 (*list):
    return [element for element in list if element > 0]

print ("-------------------------------")
list = [-3, -1, -7, -10, -12, 4]
print (f4(*list))
print ("-------------------------------")

def f5 (f):
    def wrapper(*args):
        sum = 0
        for element in list:
            sum += element
        return sum
    return wrapper

@f5
def f(a,b):
    return a + b
print ("-------------------------------")
list = [3, 5, 1, 10]
print (f(*list))
print ("-------------------------------")
