import random

def display_hash(hashTable):

    for i in range (len(hashTable)):
        print (i, end = " ")
        
        for j in hashTable[i]:
            print ("-->", end = " ")
            print (j, end = "\n ")
    
    print ()

HashTable = [[] for _ in range(11)]


def hash_function(key):
    return key % 11

def insert_hash(HashTable, value ):
    hash_key = hash_function(value)
    HashTable[hash_key].append(value)

""" def hash_search(hashTable, key):
    for i in range(len(hashTable)):
        for j in range (len(hashTable[i])):
            if hashTable[i][j] == key:
                print (hashTable[i][j], end = "") 
 """
array = []
#hash_key = int(input())
tmp = 0 

for i in range (1, 1000):
    array.append(random.randint(1,1000))

while tmp < len(array):
    insert_hash(HashTable,array[tmp])
    tmp += 1


display_hash(HashTable)

    