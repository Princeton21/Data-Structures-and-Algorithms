import random, time
from datetime import datetime, timedelta

times, start_time = int(input("How many operations would you like to do? ")), datetime.now()
timea, timeb, timec, timed = start_time.day, start_time.hour, start_time.minute, start_time.second

for x in range(times):
    n1, n2, op = random.randint(0, 10), random.randint(0, 10), random.randint(1, 3)
    if op == 1: #addition
        print("{} + {}".format(n1, n2))
        answer = int(input())
        if answer != n1 + n2: print("Wrong.")
    if op == 2: #subtraction
        print("{} - {}".format(n1, n2))
        answer = int(input())
        if answer != n1 - n2: print("Wrong.")
    if op == 3:
        print("{} * {}".format(n1, n2))
        answer = int(input())
        if answer != n1 * n2: print("Wrong.")

end_time = datetime.now()
timediff = end_time - timedelta(days=timea, hours=timeb, minutes=timec, seconds=timed) 
print("Congratulations! Your time was {}". format(timediff.strftime("%X")))
