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
    

dec = Deque()

dec.addRear(6)
dec.addRear(7)
dec.addRear(3)
dec.addFront(9)
dec.addFront(5)
dec.addFront(4)

print (dec.removeFront())
print (dec.removeRear())