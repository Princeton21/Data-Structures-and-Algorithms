total_money = 10000
if __name__=='__main__':

    print("             █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n"
          "             █░░╦─╦ ╔╗ ╦  ╔╗ ╔╗ ╔╦╗ ╔╗░░█\n"
          "             █░░║║║ ╠─ ║  ║  ║║ ║║║ ╠─░░█\n"
          "             █░░╚╩╝ ╚╝ ╚╝ ╚╝ ╚╝ ╩─╩ ╚╝░░█\n"
          "             █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n")
    print('~~WELCOME TO THE CASINO TERMINAL.... '
          '\n ..THE ALL NEW GAMING PLATFORM! ')
    name = str(input('\n ~~Please enter your name: '))
    age = int(input('\n What is your age : '))


    print("\n ")


    game=True

    while game:
        if age>18:
            print("\n ~~HELLO", name, ",your wallet contains", total_money, "$")
            choice = -1
            print('\n Enter 1 for Playing the 7UP-7DOWN Game \n')
            print('Enter 2 for Playing Blackjack Game\n')
            print('Enter 3 for Playing Roulette Wheel Game\n')
            while choice>3 or choice<1:
                choice = int(input('Enter your choice:'))
                if (choice == 1):
                    exec(open('SevenUP_SevenDOWN.py').read())
                if (choice == 2):
                    exec(open('Blackjack.py').read())
                if (choice == 3):
                        exec(open('Roulette.py').read())

            quitter = input("\nDo you want to play another game(y/n)?")
            if quitter == 'y' or quitter == 'Y':
                game = True
            elif quitter == 'n' or quitter == 'N':
                game= False
                print("\n ~~HELLO", name, ",your wallet contains", total_money, "$")
                print("\nThank you for playing with TERMINAL CASINO and hope to see you again", name)

        else:
            print('You can only play Blackjack as you are underage !')
            exec(open('Blackjack.py').read())
            quitter = input("\nDo you want to play another game(y/n)?")
            if quitter == 'y' or quitter == 'Y':
                game = True

            elif quitter == 'n' or quitter == 'N':
                game = False

                print("\nThank you for playing with TERMINAL CASINO and hope to see you again", name)

