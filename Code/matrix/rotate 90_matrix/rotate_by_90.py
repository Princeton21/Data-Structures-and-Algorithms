def rotateclock(m):
    n=len(m)
    for i in range(n):
        for j in range(i):
            temp=m[i][j]
            m[i][j]=m[j][i]
            m[j][i]=temp
        
    #CLOCKWISE
    #swap columns      
    for i in range(n):
        for j in range(n//2):
            temp=m[i][j]
            m[i][j]=m[i][n-j-1]
            m[i][n-j-1]=temp
            
def rotateanticlock(m): 
    n=len(m)
    for i in range(n):
        for j in range(i):
            temp=m[i][j]
            m[i][j]=m[j][i]
            m[j][i]=temp
                          
    #ANTI-CLOCKWISE
    #swap rows   
    for i in range(n//2):
        for j in range(n):
            temp=m[i][j]
            m[i][j]=m[n-i-1][j]
            m[n-i-1][j]=temp
                
    

if __name__ == '__main__':
 
    mat = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]
 
    n = len(mat)
 
    rotateclock(mat)
 
    for i in range(n):
        print(mat[i])  
        
    mat1 = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ] 
        
    rotateanticlock(mat1)
    print('--------------')
    for i in range(n):
        print(mat1[i])
    
    
        
                
                