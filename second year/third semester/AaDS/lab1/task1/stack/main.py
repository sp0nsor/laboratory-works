class Stack:
     def __init__(self):
         self.items = []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()


steck = Stack()

steck.push(2)
steck.push(4)
steck.push(8)

print (steck.pop())