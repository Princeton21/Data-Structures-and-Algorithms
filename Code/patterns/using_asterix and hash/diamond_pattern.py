t=int(input())
n=(t-1)//2
s=1
storage=[]
for i in range(n):
    if i==0:
        a='-'*n+'*'+'-'*n
    elif i==n-1:
        a='*'+' '*(t-2)+'*'
    else:
        c=(n-i-1)
        left='|'+' '*c+'*'
        rgt=' '*s+left[::-1]
        s+=2
        a=left+rgt
        storage.append(a)
    print(a)
for j in range(len(storage)-1,-1,-1):
    print(storage[j])
print('-'*n+'*'+'-'*n)