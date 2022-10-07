class Queue:
    def __init__(self):
        self.items = []
    
    def push (self, item):
        self.items.insert(0, item)
    
    def pop (self):
        return self.items.pop()

class Stack:
     def __init__(self):
         self.items = []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

class Deque:
    def __init__(self):
        self.items = []
    
    def addFront(self,item):
        self.items.append(item)
    
    def addRear(self, item):
        self.items.insert(0,item)
    
    def removeFront(self):
        return self.items.pop()
    
    def removeRear(self):
        return self.items.pop(0)


queue = Queue()
stack = Stack()
deque = Deque()

stack.push(1)
stack.push(2)
stack.push(3)

while (True):
    if(len(stack.items) != 0):
        tmp = stack.pop()
        queue.push(tmp)
    else:
        break

while (True):
    if (len (queue.items) != 0):
        tmp = queue.pop()
        deque.addRear(tmp)
    else:
        break

print (deque.removeFront())
print (deque.removeRear())