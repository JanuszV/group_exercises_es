import sys
import math
from datetime import  datetime, date

def language_ver():
    print("You are using Python ",sys.version)

def date_time():
    calendar_date = date.today()
    x = datetime.now()
    print("Today's date': {} and it is {} o'clock.".format(calendar_date, x.strftime("%X")))

def hello_world():
    colors = ['\033[0;31m', '\033[38;5;208m', '\033[1;33m', '\033[0;32m', '\033[0;36m', '\033[0;34m', '\033[0;35m']
    index = 0
    text = "Hello, World!!!"
    for letter in text:
        print(colors[index], letter, '\033[0m', end='')
        index += 1
        if index > 6:
            index = 0
    print("\n")

def calculate_radius(radius):
    area = pow(radius, 2) * math.pi
    print (area)

def name_switch(first, last):
    print("Hello there", last, first)

print("""Hi! Please choose an action:
1. Display Python version.
2. Display the current time and date.
3. I want to see a rainbow colored \"Hello, World!\"!
4. Calculate the area of a circle using a user-provided radius as input.
5. Take user inputs for their first and last names, then reverse the order of the names, add a space between them, and display the result as a single output.
0. Exit.""")



while True:
    action = input()

    match action:
        case "1":
            language_ver()
        case "2":
            date_time()
        case "3":
            hello_world()
        case "4":
            r = int(input("What is the radius of the circle?: "))
            calculate_radius(r)
        case "5":
            f = input("What is your first name? ")
            l = input("What is your last name? ")
            name_switch(f, l)
        case _:
            break
        
    print("Choose another action:")

    