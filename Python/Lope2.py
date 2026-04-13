import math
from turtle import *

def hearta(k):
    return 15*math.cos(k)

def heartb(k):
    return 12*math.sin(k)-5*math.sin(2*k)-2*math.sin(3*k)-math.sin(4*k)
    


speed(10)

bgcolor("black")
for i in range(360):
    goto(hearta(i)*20, heartb(i)*20)
    color("red")   
    goto(0,0)
done()