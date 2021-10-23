n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    diff = x-y

    if diff > 1:
        print("YES")
    else:
        print("NO")
