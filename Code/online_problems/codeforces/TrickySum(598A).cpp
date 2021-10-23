t=int(input())
while(t):
    n=int(input())
    c=0
    for i in range(0,n):
        if(2**i>n):
            break
        else:
            c+=1
    #print(c)
    res=2**c-1
    ans=n*(n+1)//2-(2*res)
    print(ans)
    t-=1
