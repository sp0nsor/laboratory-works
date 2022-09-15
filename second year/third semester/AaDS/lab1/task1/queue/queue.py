class Queue:
    def __init__(self):
        self.items = []
    
    def push (self, item):
        self.items.insert(0, item)
    
    def pop (self):
        return self.items.pop()


qwe = Queue()

qwe.push(1)
qwe.push(2)
qwe.push(3)
qwe.push(4)

print (qwe.pop())