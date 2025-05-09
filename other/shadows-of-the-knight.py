#https://www.codingame.com/ide/puzzle/shadows-of-the-knight-episode-1

import sys
import math

def left(x, leftmost, w):
    jump = int((x - leftmost) / 2)
    return (x - jump) ,leftmost, w-1

def right(x, leftmost, w):
    jump = int((w + 1 - x) / 2)
    return (x + jump) , leftmost + 1, w

def up(y, top, h):
    jump = int((y - top) / 2)
    return (y - jump), top, h-1

def down(y, top, h):
    jump = int((h + 1 - y) / 2)
    return (y + jump), top+1, h-1

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]

top = 0
leftmost = 0

#current pos
x=x0
y=y0

# game loop
while True:
    bomb_dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    print("bomb dir " + bomb_dir,  file=sys.stderr, flush=True)
    print("TOP " + str(top) + " h " + str(h),  file=sys.stderr, flush=True)
   

    if bomb_dir.find('U') >= 0:
        y,top,h = up(y, top, h)
    
    if bomb_dir.find('R') >= 0:
        x, leftmost, w= right(x, leftmost, w)
    
    if bomb_dir.find('D') >= 0:
        y, top, h = down(y, top, h)

    if bomb_dir.find('L') >= 0:
        x, leftmost, w= left(x, leftmost, w)   


    # the location of the next window Batman should jump to.
    print("NEXT LOCATION",  file=sys.stderr, flush=True)
    print(str(x) + " " + str(y))


