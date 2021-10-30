class circular_queue:
    def __init__(self,s):
        self.cap=s
        self.q=[None]*s
        self.f=self.r=-1      
        
    def full(self):
        return ((self.r+1)%self.cap==self.f)
    def empty(self):
        return self.f==-1
    
    def enque(self,d):
        if self.full():
            print('Full')
        elif self.empty():
            self.f=0
            self.r=0
            self.q[self.r]=d
        else:
            self.r=(self.r+1)%self.cap
            self.q[self.r]=d
            
    def deque(self):
        if self.empty():
            print('Empty')
        elif self.f==self.r:
            t=self.q[self.f]
            self.f=-1
            self.r=-1
            return t
        else:
            t=self.q[self.f]
            self.f=(self.f+1)%self.cap
            return t
        
    def display(self):
        if self.empty():
            print('Empty')
        elif self.r>=self.f:
            print("Elements in the circular queue are:", end = " ")
            for i in range(self.f,self.r+1):
                print(self.q[i],end=' ')
            print()
        else:
            print("Elements in the circular queue are:", end = " ")
            for i in range(self.f,self.cap):
                print(self.q[i],end=' ')
            for i in range(0,self.r+1):
                print(self.q[i],end=' ')
            print()
        if self.full():
            print('full')

ob = circular_queue(5)
ob.enque(14)
ob.enque(22)
ob.enque(13)
ob.enque(-6)
ob.display()
print ("Deleted value = ", ob.deque())
print ("Deleted value = ", ob.deque())
ob.display()
ob.enque(9)
ob.enque(20)
ob.enque(5)
ob.display()
                                             