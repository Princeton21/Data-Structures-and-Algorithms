def sortStack(s):
    tmpstack=[]
    while len(s)>0:
        temp=s[-1]
        s.pop()
        '''if > this sign given then decrement order'''
        while len(tmpstack)>0 and tmpstack[-1]<temp: 
            s.append(tmpstack[-1])
            tmpstack.pop()            
        tmpstack.append(temp)
    return tmpstack

def sortarrayusingstack(a,n):
    b=[]
    i=0
    while i<n:
        b.append(a[i])
        i+=1
    tmpstack=sortStack(b)
    i=0
    while i<n:
        a[i]=tmpstack[-1]
        tmpstack.pop()
        i+=1
    return a

a=[5,45,15,10]
n=len(a)
sortarrayusingstack(a,n)
i=0
while i<n:
    print(a[i],end=' ')
    i+=1
print()
    