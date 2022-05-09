import random

def insertion_sort(arr):
    for i in range (1, len(arr)):
        key = arr[i]
        j = i - 1
        while j > 0 and key < arr[j]:
            arr[j +1] = arr[j]
            j -= 1
            arr[j + 1] = key


arr = []
n = int(input('Size array > '))
for k in range(1, n+1):
    arr.append(random.randint(-10, 100))
print ('UNsorted array: ', arr)
insertion_sort(arr)
print ('Sorted array: ', arr)

