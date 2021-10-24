"""
# Square Pyramids in numbers

Output:

1 2 3 4 5 
2 2 3 4 5 
3 3 3 4 5 
4 4 4 4 5 
5 5 5 5 5 

"""
def square_pyramid(n):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if j <= i:
                print(i, end=' ')
            else:
                print(j, end=' ')
        print()


rows = 5
square_pyramid(rows)