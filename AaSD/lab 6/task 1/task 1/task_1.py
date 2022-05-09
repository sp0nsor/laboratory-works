import random

def selection_sort(alist):

    for i in range (0, len (alist) -1):
        smallest = i
        for j in range (i +1, len(alist)):
            if alist[j] < alist[smallest]:
                smallest  = j
        alist[i], alist[smallest] = alist[smallest], alist[i]


alist = []
n = int(input('size array >'))
for k in range(1, n+1):
    alist.append(random.randint(-10, 100))
print('unsorted array: ', alist)
selection_sort(alist)
print('sorted array: ', alist)