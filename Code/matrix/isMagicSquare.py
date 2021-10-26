def isMagicSquare(a):
    n=len(a)
    sumd1=sumd2=0
    for i in range(n):
        sumd1+=a[i][i]  #left diagonal
        sumd2+=a[i][n-i-1]      #right diagonal
    if sumd1!=sumd2:
        return False
    for i in range(n):
        sumr=0
        sumc=0
        for j in range(n):
            sumr+=a[i][j]
            sumc+=a[j][i]
        if not(sumr==sumc==sumd1==sumd2):
            return False
    return True

mat = [ [ 2, 7, 6 ],
        [ 9, 5, 1 ],
        [ 4, 3, 8 ] ]
     
if (isMagicSquare(mat)) :
    print( "Magic Square")
else :
    print( "Not a magic Square")        