import random 

def printDice(n):
    if n == 1:
        print('|-----------|')
        print('|           |')
        print('|     O     |')
        print('|           |')
        print('|-----------|')
    elif n == 2:
        print('|-----------|')
        print('|           |')
        print('|   O   O   |')
        print('|           |')
        print('|-----------|')
    elif n == 3:
        print('|-----------|')
        print('|  O        |')
        print('|     O     |')
        print('|        O  |')
        print('|-----------|')
    elif n == 4:
        print('|-----------|')
        print('| O       O |')
        print('|           |')
        print('| O       O |')
        print('|-----------|')
    elif n ==5:
        print('|-----------|')
        print('| O       O |')
        print('|     O     |')
        print('| O       O |')
        print('|-----------|')
    else:
        print('|-----------|')
        print('| O   O   O |')
        print('|           |')
        print('| O   O   O |')
        print('|-----------|')

def main():
    while True:
        print("Press s to throw Dice...   ",end='')
        c= input()
        if len(c)==1 and c[0]=='s':
            res = random.randrange(1,6)
            printDice(res)
        elif c[0]=='0':
            return
        else:
            print("Invalid Response")
print("This Dice gives random generated numbers, Press 's' to start the game,'0' to stop")
main()
print("Thank you for using the program.")