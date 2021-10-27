from pygame import mixer
import turtle

mixer.init()  # initiate the mixer instance

# Window
wind = turtle.Screen()
wind.title('PONG GAME')
wind.bgcolor('gray')
wind.setup(width=800, height=600)
wind.tracer(0)

# Bar A
bar_A = turtle.Turtle()
bar_A.shape('square')
bar_A.color('yellow')
bar_A.shapesize(stretch_wid=6, stretch_len=1)
bar_A.penup()
bar_A.goto(-350, 0)

# Bar B
bar_B = turtle.Turtle()
bar_B.shape('square')
bar_B.color('red')
bar_B.shapesize(stretch_wid=6, stretch_len=1)
bar_B.penup()
bar_B.goto(350, 0)

# Ball
ball = turtle.Turtle()
ball.shape('circle')
ball.color('green')
ball.penup()
ball.goto(0, 0)
ball_x = 0.1
ball_y = 0.1

# score
sboard = turtle.Turtle()
sboard.shape('square')
sboard.color('orange')
sboard.penup()
sboard.hideturtle()
sboard.goto(0, 260)
sboard.write("Player A: 0 \t Player B: 0",
             align="center", font=("Calibri", 26, 'bold'))

score_a = 0
score_b = 0


# Functions
def bar_A_up():
    y = bar_A.ycor()
    y += 30
    bar_A.sety(y)


def bar_A_down():
    y = bar_A.ycor()
    y -= 30
    bar_A.sety(y)


def bar_B_up():
    y = bar_B.ycor()
    y += 30
    bar_B.sety(y)


def bar_B_down():
    y = bar_B.ycor()
    y -= 30
    bar_B.sety(y)


# Keyboard Bindings
wind.listen()
wind.onkeypress(bar_A_up, 'w')
wind.onkeypress(bar_A_down, 's')
wind.onkeypress(bar_B_up, 'Up')
wind.onkeypress(bar_B_down, 'Down')


while True:
    wind.update()

    # BAll movement
    ball.setx(ball.xcor() + ball_x)
    ball.sety(ball.ycor() + ball_y)

    # Left Border
    if ball.ycor() > 290:
        ball.sety(290)
        ball_y *= -1
    elif ball.ycor() < -290:
        ball.sety(-290)
        ball_y *= -1

    # score count
    if ball.xcor() > 350:
        score_a += 1
        sboard.clear()
        sboard.write("Player A: {} \t Player B: {}".format(
            score_a, score_b), align='center', font=("Calibri", 26, 'bold'))
        ball.goto(0, 0)
        ball_x *= -1
        mixer.music.load('wallhit.wav')
        mixer.music.play()
    elif ball.xcor() < -350:
        score_b += 1
        sboard.clear()
        sboard.write("Player A: {} \t Player B: {}".format(
            score_a, score_b), align='center', font=("Calibri", 26, 'bold'))
        ball.goto(0, 0)
        ball_x *= -1
        mixer.music.load('wallhit.wav')
        mixer.music.play()

    # Collision with bars
    if ball.xcor() < -340 and ball.ycor() < bar_A.ycor() + 50 and ball.ycor() > bar_A.ycor() - 50:
        ball_x *= -1
        mixer.music.load('paddle.wav')
        mixer.music.play()
    elif ball.xcor() > 340 and ball.ycor() < bar_B.ycor() + 50 and ball.ycor() > bar_B.ycor() - 50:
        ball_x *= -1
        mixer.music.load('paddle.wav')
        mixer.music.play()
