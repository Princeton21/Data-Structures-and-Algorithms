def createTranspose(inputMatrix,n,m):
    transposeMatrix = [[0 for x in range(n)] for y in range(m)]
    for i in range(n):
        for j in range(m):
            transposeMatrix[j][i] = inputMatrix[i][j]
    return transposeMatrix
    
n = int(input("Enter number of raws :"))
m = int(input("Enter number of columns :"))
matrix = [[0 for x in range(m)] for y in range(n)] 
for i in range(n):
    for j in range(m):
        matrix[i][j] = int(input("Enter "+str(i)+","+str(j)+"th element : "))

print("Transpose matrix :")
transpose = createTranspose(matrix,n,m)
for i in range(m):
    for j in range(n):
        print(transpose[i][j], " ", end='')
    print() 