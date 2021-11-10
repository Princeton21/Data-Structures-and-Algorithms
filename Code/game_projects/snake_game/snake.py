"""
the right, left, up and down keycode values ​​on the keyboard have different values... please check below

#for windows users, please change the value of checking the keycode as shown below
            if event.keycode == 38:
                self.direction = "up"
            elif event.keycode == 39:
                self.direction = "right"
            elif event.keycode == 40:
                self.direction = "down"
            elif event.keycode == 37:
                self.direction = "left"

#for linux users, please change the keycode checking value as shown below
            if event.keycode == 111:
                self.direction = "up"
            elif event.keycode == 114:
                self.direction = "right"
            elif event.keycode == 116:
                self.direction = "down"
            elif event.keycode == 113:
                self.direction = "left"
"""


import threading
import random
import os.path
from tkinter import *

WIDTH = 500
HEIGHT = 500

class Snake(Frame):

    def __init__(self):
        Frame.__init__(self)

        self.master.title(Snake)
        self.grid()

        frame1 = Frame(self)
        frame1.grid()

        self.canvas = Canvas(frame1, width = WIDTH, height = HEIGHT, bg ="white")
        self.canvas.grid(columnspan = 3)
        self.canvas.focus_set()
        self.canvas.bind("<Button-1>", self.create)
        self.canvas.bind("<Key>", self.create)

        newGame = Button(frame1, text = "Restart Game", command = self.new_game)
        newGame.grid(row = 1, column = 0, sticky = E)

        self.score_label = Label(frame1)
        self.score_label.grid(row = 1, column = 1)

        self.high_score_label = Label(frame1)
        self.high_score_label.grid(row = 1, column = 2)

        self.new_game()

    def new_game(self):
        self.canvas.delete(ALL)
        self.canvas.create_text(WIDTH/2,HEIGHT/2-50,text="Welcome In Snake Game!"\
                                + "\nclick the window or press one of the directional keys"
                                + "\nTo start this game..", tag="welcome_text")

        rectWidth = WIDTH/25

        rect1 = self.canvas.create_rectangle(WIDTH/2-rectWidth/2, HEIGHT/2-rectWidth/2, WIDTH/2+rectWidth/2\
                                             , HEIGHT/2+rectWidth/2, outline="#dbf", fill="#dbf"\
                                             , tag="rect1")
        rect2 = self.canvas.create_rectangle(WIDTH/2-rectWidth/2, HEIGHT/2-rectWidth/2, WIDTH/2+rectWidth/2\
                                             , HEIGHT/2+rectWidth/2, outline="#dbf", fill="#dbf"\
                                             , tag="rect2")
        rect3 = self.canvas.create_rectangle(WIDTH/2-rectWidth/2, HEIGHT/2-rectWidth/2, WIDTH/2+rectWidth/2\
                                             , HEIGHT/2+rectWidth/2, outline="#dbf", fill="#dbf"\
                                             , tag="rect3")



        self.rectWidth = rectWidth
        self.lastDirection = None
        self.direction = None
        self.started = False
        self.game_over = False
        self.score = 0


        if (os.path.isfile("high_score.txt")):
            scoreFile = open("high_score.txt")
            self.high_score = int(scoreFile.read())
            scoreFile.close()
        else:
            self.high_score = 0

        self.high_score_label["text"] = "High Score: " + str(self.high_score)

        self.rectangles = [rect1,rect2,rect3]

        self.dot = None

        self.move()


    def create(self, event):
        self.lastDirection = self.direction
        if self.game_over == False:
            if event.keycode == 38: #For linux user the value is 111
                self.direction = "up"
            elif event.keycode == 39: #For linux user the value is 114
                self.direction = "right"
            elif event.keycode == 40: #For linux user the value is 116
                self.direction = "down"
            elif event.keycode == 37: #For linux user the value is 113
                self.direction = "left"
            elif event.x < WIDTH/2 and HEIGHT/3 < event.y < HEIGHT-HEIGHT/3:
                self.direction = "left"
            elif event.x > WIDTH/2 and HEIGHT/3 < event.y < HEIGHT-HEIGHT/3:
                self.direction= "right"
            elif WIDTH/3 < event.x < WIDTH-WIDTH/3 and event.y < HEIGHT/2:
                self.direction = "up"
            elif WIDTH/3 < event.x < WIDTH-WIDTH/3 and event.y > HEIGHT/2:
                self.direction= "down"

    def first_movement(self):
        w = self.rectWidth
        self.canvas.delete("welcome_text")

        if self.direction == "left":
                self.canvas.move("rect1",-w,0)
                self.canvas.after(100)
                self.canvas.move("rect1",-w,0)
                self.canvas.move("rect2",-w,0)
        elif self.direction == "down":
                self.canvas.move("rect1",0,w)
                self.canvas.after(100)
                self.canvas.move("rect1",0,w)
                self.canvas.move("rect2",0,w)
        elif self.direction == "right":
                self.canvas.move("rect1",w,0)
                self.canvas.after(100)
                self.canvas.move("rect1",w,0)
                self.canvas.move("rect2",w,0)
        elif self.direction == "up":
            self.canvas.move("rect1",0,-w)
            self.canvas.after(100)
            self.canvas.move("rect1",0,-w)
            self.canvas.move("rect2",0,-w)
        self.canvas.after(100)

    def _move(self):
        w = self.rectWidth
        while True:
            self.score_label["text"] = "Score: " + str(self.score)
            if self.started == False and self.direction != None:
                self.first_movement()
                self.started = True
            elif self.started == True and self.game_over == False:
                if self.dot == None:
                    self.make_new_dot()
                lock = threading.Lock()
                lock.acquire()
                endRect = self.rectangles.pop()
                frontCoords = self.canvas.coords(self.rectangles[0])
                endCoords = self.canvas.coords(endRect)

                if self.direction == "left":
                    self.canvas.move(self.canvas.gettags(endRect), int(frontCoords[0]-endCoords[0])-w,\
                                     int(frontCoords[1]-endCoords[1]))
                elif self.direction == "down":
                    self.canvas.move(self.canvas.gettags(endRect), int(frontCoords[0]-endCoords[0]),\
                                     int(frontCoords[1]-endCoords[1])+w)
                elif self.direction == "right":
                    self.canvas.move(self.canvas.gettags(endRect), int(frontCoords[0]-endCoords[0])+w,\
                                     int(frontCoords[1]-endCoords[1]))
                elif self.direction == "up":
                    self.canvas.move(self.canvas.gettags(endRect), int(frontCoords[0]-endCoords[0]),\
                                     int(frontCoords[1]-endCoords[1])-w)
                self.canvas.after(100)
                self.rectangles.insert(0, endRect)
                lock.release()
                self.check_bounds()
                self.check_collide()
            elif self.game_over == True:
                break;

    def move(self):
        threading.Thread(target=self._move).start()

    def make_new_dot(self):
        if self.dot != None:
            self.canvas.delete(self.dot)
            self.dot = None
        dotX = random.random()*(WIDTH-self.rectWidth*2) + self.rectWidth
        dotY = random.random()*(HEIGHT-self.rectWidth*2) + self.rectWidth
        self.dot = self.canvas.create_rectangle(dotX,dotY,dotX+self.rectWidth,dotY+self.rectWidth\
                                                ,outline="#ddd", fill="#ddd", tag="dot")

    def grow(self):
        w = self.rectWidth
        lock = threading.Lock()
        lock.acquire()

        self.score += 100

        endCoords = self.canvas.coords(self.rectangles[len(self.rectangles)-1])

        thisTag = "rect" + str(len(self.rectangles) + 1)
        x1 = int(endCoords[0])
        y1 = int(endCoords[1])
        x2 = int(endCoords[2])
        y2 = int(endCoords[3])

        if self.direction == "left":
            x1 += w
            x2 += w
        elif self.direction == "right":
            x1 -= w
            x2 -= w
        elif self.direction == "down":
            y1 -= w
            y2 -= w
        elif self.direction == "up":
            y1 += w
            y2 += w

        thisRect = self.canvas.create_rectangle(x1, y1, x2, y2, outline="#dbf",\
                                     fill="#dbf", tag=thisTag)
        self.rectangles.append(thisRect)
        lock.release()


    def check_bounds(self):
        coordinates = self.canvas.coords(self.rectangles[0])
        if len(coordinates) > 0:
            if coordinates[0] < 0 or coordinates[1] < 0 or coordinates[2] > WIDTH\
               or coordinates[3] > HEIGHT:
                self.end_game()

    def check_collide(self):
        frontCoords = self.canvas.coords(self.rectangles[0])

        overlapping = self.canvas.find_overlapping(frontCoords[0],frontCoords[1]\
                                                         ,frontCoords[2],frontCoords[3])
        for item in overlapping:
            if item == self.dot:
                #Snake collided with dot, grow snake and move dot
                self.grow()
                self.make_new_dot()
            if item in self.rectangles[3:]:
                #Snake has collided with its body, end game
                self.end_game()


        if (self.lastDirection == "left" and self.direction == "right") or\
           (self.lastDirection == "right" and self.direction == "left") or\
           (self.lastDirection == "up" and self.direction == "down") or\
           (self.lastDirection == "down" and self.direction == "up"):
            self.end_game()

    def end_game(self):
        self.game_over = True
        self.canvas.create_text(WIDTH/2,HEIGHT/2,text="GAME OVER!")
        if self.score > self.high_score:
            scoreFile = open("high_score.txt", "w")
            scoreFile.write(str(self.score))
            scoreFile.close()
            self.canvas.create_text(WIDTH/2,HEIGHT/2+20,text=\
                                    "Wow you got new high score")

Snake().mainloop()