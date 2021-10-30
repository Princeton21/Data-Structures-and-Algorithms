def swap_diagonal(m):
    n=len(m)
    for i in range(n):
        m[i][i],m[i][n-i-1]=m[i][n-i-1],m[i][i]
        
    for i in range(n):
        for j in range(n):
            print(m[i][j],end=' ')
        print(' ')
        
matrix = [[0, 1, 2],
          [3, 4, 5],
          [6, 7, 8]]
 
# swap diagonals of matrix
swap_diagonal(matrix)
 