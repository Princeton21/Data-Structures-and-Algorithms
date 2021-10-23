import random
from time import sleep
import Terminal_Casinogame
import math



game_on = True

while game_on :
    print("\nYou start the game with!", total_money, '$ \n')
    bet_value = -1

    # choose the square on which we put
    while bet_value < 0 or bet_value > 50:
        try:
            print("Choose the bet number[0,50]")
            bet_value = int(input("What is your choice? ..."))
        except ValueError:
            print("you haven't introduced anything.")
            bet_value = -1
        if bet_value < 0:
            print("you must choose a number greater than 0.")
        elif bet_value > 50:
            print("you must choose a number less than 50.")

    print("You chose", bet_value)

    # choose the amount to bet on the number
    money_to_bet = 0
    while money_to_bet <= 0 or money_to_bet > total_money:
        money_to_bet = input("\nWhat is your stake?")
        try:
            money_to_bet = int(money_to_bet)
        except ValueError:
            print("you did not choose your stake.")
        if money_to_bet <= 0:
            print("The bet is negative or zero.")
        if money_to_bet > total_money:
            print("You don't have enough money. You have", total_money)

    # start roulette
    print("\nThe croupier launches the roulette wheel ...")
    number_landed = random.randrange(0, 50)
    sleep(2)
    print("the roulette wheel stops on", number_landed)

    # processing
    if number_landed == bet_value:
        print("\nYou bet on the right number, you win", money_to_bet *3, '$')
        total_money += money_to_bet * 3
    elif number_landed % 2 == bet_value % 2:
        print("\nYou bet on the right color, you win", math.ceil(money_to_bet * 0.5), '$')
        total_money += math.ceil(money_to_bet * 0.5)
    else:
        print("\nSorry you lost", money_to_bet, '$')
        total_money -= money_to_bet

    # Game over
    if total_money <= 0:
        print("\nYou're ruined, it's the end of the party")
        game_on = False
    else:
        print("\nyou have now", total_money, '$')
        quitter = input("\nDo you want to quit the game(y/n)?")
        if quitter == 'y' or quitter == 'Y':
            print("\nYou leave the casino with", total_money, '$')
            game_on = False
            print("\nThank you for playing ROULETTE")

