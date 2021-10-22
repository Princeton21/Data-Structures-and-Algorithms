import random   #importing random
def Rolldice(rolls):
    for i in range(0,rolls):
        number=random.randint(1,6)  #random.randint is a very useful function to give random numbers
        print("---")
        print("-"+str(number)+"-")
        print("---")
        print()
    Menu()

def Menu():
    print("1.Roll a dice:")#roll for one dice
    print("2.Roll multiple dice:")# roll for multiple dice
    print("-----------------------")
    print("3.Exit from Game")  #exit() function to exit from game.
    choice=int(input("Enter choice:"))

    if choice==1:
        Rolldice(1)
    if choice==2:
        rolls=int(input("Enter no. of rolls:"))
        Rolldice(rolls)     #call for multiple rolls
    if choice==3:
        print("Out of the Game")
        exit();
Menu()
