from random import choice

# list of words(fruits and vegetables)
words=["apple","banana","orange","kiwi","pine","melon","potato","carrot","tomato","chilly","pumpkin","brinjol","cucumber","olive","pea","corn","beet","cabbage","spinach"]
c_word = choice(words)
lives=3
unknown = ["_"]*len(c_word)
 
while lives>0:
    guess=input("Please guess a letter or word: ")
    if guess == c_word:
        print('You won! The secret word was ' + c_word)
        break
    elif guess in c_word:
        unknown[c_word.index(guess)]=guess
        if "_" in unknown:
            print(unknown)
            print("Hurray!,you succeded in guessing a letter correct.go ahead!")
            print(f"chances left are {lives}")
        else:
            print(unknown)
            print("Congrats!\nyou won!")
    else:
        if lives==1:
            print(unknown)
            print("you are run out of lifes.\nBetter luck nect time!")
        elif lives>0:
            print(unknown)
            print("you lost a life.try again!")
            print(f"chances left are {lives}")
        lives=lives-1


