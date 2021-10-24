#Solution of codeforces problem Vupsen, Pupsen and 0, https://codeforces.com/contest/1582/problem/D

for testcases in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    
    if(n%2==0):
        for i in range(0,n,2):
            if(a[i]/abs(a[i])==1):
                b.append(abs(a[i+1]))
            else:
                b.append( abs(a[i+1]) * (-1) )
            if(a[i+1]/abs(a[i+1])==1):
                b.append(-1*abs(a[i]))
            else:
                b.append( abs(a[i]) )
                
    else:
        if(a[0]/abs(a[0])==1):
            b.append(abs(a[2]))
        else:
            b.append(-abs(a[2]))
            
        if(a[1]/abs(a[1])==1):
            b.append(abs(a[2]))
        else:
            b.append(-abs(a[2]))
            
        if(a[2]/abs(a[2])==1):
            b.append(-abs(a[1])-abs(a[0]))
        else:
            b.append(abs(a[1])+abs(a[0]))
            
        for i in range(3,n,2):
            if(a[i]/abs(a[i])==1):
                b.append(abs(a[i+1]))
            else:
                b.append( abs(a[i+1]) * (-1) )
            if(a[i+1]/abs(a[i+1])==1):
                b.append(-1*abs(a[i]))
            else:
                b.append( abs(a[i]) )
                
    for i in b:
        print(i,end=" ")
    print()