import random 

def buble_sort(arr):

    for i in range(len(arr)):
        for j in range (len(arr) - 1):
            if (arr[j] > arr[j + 1]):
                zxc = arr[j]
                arr[j] = arr[j + 1]
                arr[j+1] = zxc
    return arr

arr = []
n = int(input('Size array > '))
for k in range (1, n+1):
    arr.append(random.randint(-10,100))
print ('UNsorted array: ', arr)
buble_sort(arr)
print ('sorted array: ', arr)

