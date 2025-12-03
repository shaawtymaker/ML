import turtle

t = turtle.Turtle()
t.pensize(3)
t.speed(0)
t.color("blue")

# Draw square
for i in range(4):
    t.forward(100)
    t.right(90)

# Move and draw triangle
t.penup()
t.goto(-150, 0)
t.pendown()
t.color("red")
for i in range(3):
    t.forward(100)
    t.left(120)

# Move and draw circle
t.penup()
t.goto(150, 0)
t.pendown()
t.color("green")
t.circle(50)

# Move up and draw star
t.penup()
t.goto(-50,200)
t.pendown()
t.color("cyan")
for i in range(5):
    t.forward(150)
    t.right(144)

# Move down and draw rainbow benzene
t.penup()
t.goto(0,-200)
t.pendown()
colors = ['red', 'purple', 'blue', 'green', 'orange', 'yellow']
turtle.bgcolor('black')

for x in range(60):
    t.pencolor(colors[x % 6])
    t.width(x // 100 + 1)
    t.forward(x)
    t.left(59)

turtle.done()