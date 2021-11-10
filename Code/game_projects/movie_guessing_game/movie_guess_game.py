import random


def Movie_guess():
  # You can add more movie names if you want!
  movie_list=["Avengers","Avengers Endgame","Wandavision","Loki","Jab We Met","Dil","Hum dil de chuke sanam","Ramleela","Bajirao mastani","Padmavat","Tanu weds manu"]
  movie=random.choice(movie_list)
  movie=movie.replace(" ","")
  movie=list(movie.lower())
  length=len(movie)
  stars=list('*' * length)

  chances=5 # We're restricting the player chances by allowing only 5 wrong choice of character guessing
  while chances>0 and movie!=stars:
    ch = input("Guess any character which might present in movie name: ")
    ch=ch.lower()
    if ch in movie:
      pos=[]
      for i in range(len(movie)):
        if ch==movie[i]:
          pos.append(i)
      
      for j in pos:
        stars[j]=ch
      print(stars)
    else:
      print("\nWrong guess!! given character is not present in movie name")
      chances-=1
      if chances==0:
        print("\n NO chances left now")
      else:
        print("\n only",chances,"Chances Left now\n")

  if movie==stars:
    print("********************************************************************")
 
    print("Movie name is:",''.join(movie),"\n")
    print("********************************************************************")
    return 1

  else:
    print("********************************************************************")
    
    print("Movie name was:",''.join(movie),"\n")
    print("********************************************************************")
    return 0


score1=0
score2=0
i=3 # i represents no of times two players will play this game and whoever wins most of the times that player will be the winner, this can be changed!
result=0
p1=input("\nEnter name of player 1:")
p2=input("\nEnter name of player 2:")
r=0 #r represent round number
while i!=0:
    r=r+1
    print("\n\n**************************************Round:",r,"**************************************************************")
    print("\n " ,p1," is playing")
    result=Movie_guess()
    if result==1:
      score1+=1
    
    print("\n " ,p2," is playing")
    result=Movie_guess()
    if result==1:
      score2+=1
    print("Score board after round ",r,":","|",p1,":",score1,"|",p2,":",score2,"|")
    i=i-1

if score1==score2:
  print("\n\n ^^^^^^^^^^^^^^^^^^^^^^  Tie  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
elif score1>score2:
  print("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^  ",p1,"Won  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
else:
  print("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^  ",p2,"Won  **********************************")
  
