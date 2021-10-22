def tower_builder(n_floors):
    n_floors-=1
    ast = 1
    tower = []

    while n_floors >= 0:
        a = n_floors*" " + ast*"*"
        ast += 2
        tower.append(a)
        print(a)
        n_floors-=1

tower_builder(int(input()))
