from datetime import datetime, timedelta
import time

usa = ["alabama", "alaska", "arizona", "arkansas", "california", "colorado", "connecticut", "delaware", "florida", "georgia", "hawaii", \
    "illinois", "indiana", "idaho", "iowa", "kansas", "kentucky", "louisiana", "maine", "maryland", "massachussetts", "michigan", \
    "minnesotta", "missouri", "mississippi", "montana", "nebraska", "nevada", "new hampshire", "new jersey", "new mexico", "new york", \
    "north carolina", "north dakota", "ohio", "oklahoma", "oregon", "pennsylvania", "rhode island", "south carolina", "south dakota", \
    "texas", "tennessee", "utah", "vermont", "virginia", "washington", "west virginia", "wisconsin", "wyoming"]
start_time, acertos = datetime.now(), []
timea, timeb, timec, timed = start_time.day, start_time.hour, start_time.minute, start_time.second

x = input("Welcome to the game 50 States of the United States of America!\n" +
    "When the game starts, type one state per turn and press ENTER\n" + "If you want to give, just type 'i give up'\n" +
    "Good luck! Press ENTER to start the game!")
for n in range(5, 0, -1): #5 sec countdown
    time.sleep(1)
    print(n)
print("\n"*60) #clear scree

while True: #game
    guess = input().lower() #attempt
    if guess in usa:
        if guess in acertos: #repeated state
            print("You've already said that state!")
        else: #correct answer
            acertos.append(guess)
            print("{}/50".format(len(acertos)))
    elif guess=="i give up": #user gives up
        print("You forgot about: {} \nTotal: {} state(s)".format(list(set(usa).difference(set(acertos))), 50-len(acertos)))
        break
    else: #wrong answer
        print("{} isn't a state".format(guess))
    if len(acertos)==50: #list is complete
        end_time = datetime.now()
        timediff = end_time - timedelta(days=timea, hours=timeb, minutes=timec, seconds=timed) 
        name = input("Congrats! Your time was {}\nPlease insert your name: ".format(timediff.strftime("%X")))
        try: #try to read file w previous user stats
            f = open("50statesbestscore.txt")
            bestname, besttime = f.read().split(", ")
            a, b, c = map(int, besttime.split(":"))
            besttime = datetime(hour=a, minute=b, second=c, year=start_time.year, month=start_time.month, day=start_time.day)
            if timediff <= besttime:
                f = open("50statesbestscore.txt", "w")
                f.write("{}, {}".format(name, timediff.strftime("%X")))
                bestname, besttime = name, timediff
        except FileNotFoundError:
            f = open("50statesbestscore.txt", "w")
            f.write("{}, {}".format(name, timediff.strftime("%X")))
            bestname, besttime = name, timediff
        print("Best time of {} by {}".format(besttime.strftime("%X"), bestname))
        break