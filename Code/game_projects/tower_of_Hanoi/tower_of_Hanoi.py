from time import sleep
import os
import sys
import click


def tower(tow):
  my_str=[]
  n=len(tow)
  for i in tow:
    my_str.append( (" "*(n-i)+str(i)*i+"|")+(" "*(n-i)+str(i)*i)[::-1] )
  return(my_str)

def min_(a):
  min_val=100
  for i in a:
    if i != 0:
      if i<min_val:
        min_val=i

  if min_val != 100:
    return min_val
  else:
    return 0
  

def top_index(a):
  index=0
  for i in a:
    if i != 0:
      return int(index)
    index+=1
  return len(a)


def move_disk(start, end ):
 

  min_index_a = start.index(min_(start))
  if (min_(start) < max(end) or end[-1]==0) and min_(start) !=0 :
    end.pop(0)
    end.insert( top_index(end), start.pop(min_index_a))
    start.insert(0,0)
    return(True)

  else:
    print("Movement not allowed")
    sleep(1.5)
    return(False)
  

def print_state(a,b,c):
  A=tower(a)
  B=tower(b)
  C=tower(c)
  
  os.system('clear')  
  game_state=[]
  n=len(A)
  for i in range(0,n):
    game_state.append((A[i]+B[i]+C[i]))
    print(game_state[i])
  labelA=(" "*(n-i)+" "*i+"a")+(" "*(n-i)+" "*i)[::-1] 
  labelB=(" "*(n-i)+" "*i+"b")+(" "*(n-i)+" "*i)[::-1] 
  labelC=(" "*(n-i)+" "*i+"c")+(" "*(n-i)+" "*i)[::-1] 
  LabelT=labelA+labelB+labelC
  print("-"*3*len(labelA))
  print(LabelT)
  sys.stdout.flush()
  sleep(0.5)



def intro():

  print("Welcome to Tower of Hanoi Puzzle\n")
  print("""The objective of the puzzle is to move the entire stack from 'a' rod to 'c' rod, obeying the following rules:
    Only one disk may be moved at a time.
    Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
    No disk may be placed on top of a disk that is smaller than it.""" )

  print("\nHow to Play:")
  print(" Select rod origin, and them select destination rod")
  print("\nIn this way you can move the disk above the stack, from the source rod, towards the destination rod")
  print("You can use your keyboards keys: a b c or 1 2 3")
  print("Press 'q' to exit the game\n\n")

  print('Press any key to start the game: ') 
  click.getchar()
  os.system('clear')
  




def _game(n):
  
  #initial state
  a=list(range(n+1))
  b=[0]*(n+1)
  c=[0]*(n+1)
  win=list(range(n+1))

  def solver(n,start,aux,end):
    if n==1:
      move_disk(start,end)
      print_state(a,b,c)
    else:
      solver(n-1,start,end,aux);
      move_disk(start,end)
      print_state(a,b,c)
      solver(n-1,aux,start,end);
  #end of solver
    
  def interfaz():

    while(True):
      opt="a b c"
      input_start="x"
      input_end="x"

      while(True):

        print('Select origin rod: -> '+opt)
        input_start = str(click.getchar())
        

        if input_start == "1":
          input_start="a"

        if input_start == "2":
          input_start="b" 
          
        if input_start == "3":
          input_start="c"
          
        print(input_start)

        #exit the game
        if input_start == "q":
          return(False)

        
        if input_start not in opt:
          print("Try again")
          sleep(1.5)
        else:
          break
      
      aux_opt=opt.replace(input_start,"")
      while(True):
        print('Select destiny rod: -> '+aux_opt)
        input_end = str(click.getchar())

        if input_end == "1":
          input_end="a"

        if input_end == "2":
          input_end="b" 
          
        if input_end == "3":
          input_end="c"

        print(input_end)

        if input_end == "q":
          return(False)

        if input_end not in aux_opt:
          print("Try again")
          sleep(1.5)
        else:
          break

      
      if (input_start=="a" ):
        if(input_end=="b"):
          check_move=move_disk(a,b)
        elif(input_end=="c"):
          check_move=move_disk(a,c)
      elif(input_start=="b"):
        if(input_end=="a"):
          check_move=move_disk(b,a)
        elif(input_end=="c"):
          check_move=move_disk(b,c)
      elif(input_start=="c"):
        if(input_end=="a"):
          check_move=move_disk(c,a)
        elif(input_end=="b"):
          check_move=move_disk(c,b)

      if check_move==True:
        print_state(a,b,c)
        return True  
      else:
        continue
  ###end of interfaz

  if demo=="demo":
    solver(n,a,b,c)
      #2n − 1
    print("Number of Movement= "+str( 2**n-1 ))
    return
  print_state(a,b,c)

  #print(str(c)+'\n'+str(win))
  movement=0
  while(True):

    
    if ( interfaz() == False ):
      print("You Exit the Game")
      return
    movement+=1  
    if(c == win):
      print("You Win!")
      print("Number of Movement: "+ str(movement) +"\n")
      break
  #end of game_


#MAIN

a=list(range(4))
b=[0]*(4)
c=[0]*(4)
print_state(a,b,c)
intro()

  
while(True):
  n_disk=int(input("Select number of the disk between 3 and 9 inclusive: "))
  if n_disk >= 3 and n_disk <= 9:
    break
  else:
    print("Try again")

demo=input("Type 'demo' if you want to auto-solve the puzzle if not just press enter: ")

  

_game(n_disk)


