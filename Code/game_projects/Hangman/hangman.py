import random


def main():
    global count
    global display
    global word
    global already_guessed
    global length
    global play_game

    print("Please select the genre you want to choose: ")
    print("1. animals")
    print("2. Countries")

    animals = ["ant", "bear", "cat", "dog", "elephant", "frog", "giraffe", "horse", "iguana", "jackal", "kangaroo",
               "llama", "monkey", "newt", "owl", "penguin", "quail", "rat", "snake", "tiger", "urchin", "vulture",
               "wombat", "xeme", "yak", "zebra"]
    countries = ["afghanistan", "belgium", "canada", "denmark", "england", "finland", "ghana", "hungary", "india",
                 "japan", "kazakhstan", "lithuania", "madagascar", "nigeria", "oman", "pakistan", "qatar", "russia",
                 "switzerland", "thailand", "uganda", "venezuela", "wales", "yemen", "zimbabwe"]
    selection = int(input())
    while selection < 1 or selection > 2:
        print("Please enter a valid option")
    if selection == 1:
        words_to_guess = animals
    else:
        words_to_guess = countries

    word = random.choice(words_to_guess)
    length = len(word)
    count = 0
    display = '_' * length
    already_guessed = []
    play_game = ""
    hangman(word)


def play_loop():
    global play_game
    play_game = input("\nDo You want to play again? y = yes, n = no \n")
    while play_game not in ["y", "n", "Y", "N"]:
        play_game = input("\nDo You want to play again? y = yes, n = no \n")

    if play_game in ["y", "Y"]:
        main()
    else:
        print("Thanks For Playing! We expect you back again!")
        exit()


def hangman(word1):
    global count
    global display
    global word
    global already_guessed
    global play_game
    limit = 6
    guess = input("This is the Hangman Word: " + display + " Enter your guess: \n")
    guess = guess.strip()
    if len(guess.strip()) != 1 or guess.isalpha() is False:
        print("Invalid Input, Try a letter\n")

    elif guess in already_guessed:
        print("Try another letter.\n")

    elif guess in word1:
        already_guessed.extend([guess])
        while word1.find(guess) != -1:
            index = word1.find(guess)
            word1 = word1[:index] + '_' + word1[index + 1:]
            display = display[:index] + guess + display[index + 1:]
        print(display + "\n")

    else:
        count += 1

        if count == 1:
            print("   _____ \n"
                  "  |     |\n"
                  "  |     |\n"
                  "  |     |\n"
                  "  |     0\n"
                  "  |      \n"
                  "  |      \n"
                  "__|__    \n")
            print("Wrong guess. " + str(limit - count) + " guesses remaining\n")

        elif count == 2:
            print("   _____  \n"
                  "  |     | \n"
                  "  |     | \n"
                  "  |     | \n"
                  "  |     0 \n"
                  "  |     | \n"
                  "  |       \n"
                  "__|__     \n")
            print("Wrong guess. " + str(limit - count) + " guesses remaining\n")

        elif count == 3:
            print("   _____   \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     0  \n"
                  "  |     |\ \n"
                  "  |        \n"
                  "__|__      \n")
            print("Wrong guess. " + str(limit - count) + " guesses remaining\n")

        elif count == 4:
            print("   _____   \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     O  \n"
                  "  |    /|\ \n"
                  "  |        \n"
                  "__|__      \n")
            print("Wrong guess. " + str(limit - count) + " guesses remaining\n")

        elif count == 5:
            print("   _____   \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     O  \n"
                  "  |    /|\ \n"
                  "  |    /   \n"
                  "__|__      \n")
            print("Wrong guess. " + str(limit - count) + " last guess remaining\n")

        elif count == 6:
            print("   _____   \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     |  \n"
                  "  |     O  \n"
                  "  |    /|\ \n"
                  "  |    / \ \n"
                  "__|__      \n")
            print("Wrong guess. You are hanged!!!\n")
            print("The word was:", word)
            play_loop()

    if word1 == '_' * length:
        print("Congrats! You have guessed the word correctly!")
        play_loop()

    elif count != limit:
        hangman(word1)


main()
