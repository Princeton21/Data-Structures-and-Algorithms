lst = []
x = y = 0

for i in range(5):
    matrix = input().split()
    lst.append(matrix)

    for j in range(0, 5):
        if lst[i][j] == "1":
            x = i-2
            y = j-2
            print(abs(x) + abs(y)
