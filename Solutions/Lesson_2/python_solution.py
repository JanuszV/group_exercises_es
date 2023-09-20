import os
import datetime
import math

def create_list():
    comma_values = str(input("Please input the values of the list separated by a coma:"))
    comma_list = comma_values.split(',')
    print(comma_list)

#while finishing the aproach below I remembered about the split function
def create_list_2():
    comma_values = str(input("Please input the values of the list separated by a coma:"))
    comma_list = []
    element = ''
    for character in range(0, len(comma_values)):
        if comma_values[character] == ',':
            comma_list.append(element)
            element = ''
        elif character == len(comma_values) - 1:
            element += comma_values[character]
            comma_list.append(element)
        else:
            element += comma_values[character]
    print(*comma_list)

def check_file():
    input_file = str(input("Please input the name of the file:"))
    extensions = []
    files = os.listdir()
    for file in files:
        file_name, file_extension = os.path.splitext(file)
        if file_name == input_file:
            extensions.append(file_extension)
    print("The filename you inputed is existing with the following extensions:", extensions)

def calculate_nnnn():
    n = str(input("Choose n:"))
    m = int(n) + int(n+n) + int(n+n+n) + int(n+n+n+n)
    print("m is equal to:", m)

def two_dates():
    date_one = datetime.datetime(2018, 6, 1)
    date_two = datetime.datetime.now()
    time_between = date_two - date_one
    print (time_between)

def calculate_equation():
    i = int(input("Choose i:"))
    j = int(input("Choose j:"))
    k = int(input("Choose k:"))
    m = (i/2) * (j*j) - k
    if i == j == k:
        m *= 3
    print("i/2 * j^2 - k = ", m)
    
def display_string():
    input_string = input("Input a string:")
    n = int(input("Choose n:"))
    if len(input_string) < 2:
        print(input_string * n)
    print(input_string * n)
        
def even_odd():
    n = int(input("Choose a number:"))
    if n%2 == 0:
        print(n, "is even!")
    else:
        print(n, "is odd!")

def list_compare():
    list_a = ['apple', 'banana', 'orange', 'grape']
    list_b = ['banana', 'kiwi', 'grape']  
    list_and = set(list_a) & set(list_b)
    print("Elements unique to the first list:", set(list_a) - list_and)

#the method implemented as classic rounding is rounding away from zero 
def classic_rounding():
    n = float(input("Choose a number:"))
    if n >= 0.0:
        print("Your number rounded:", math.floor(n + 0.5))
    else:
        print("Your number rounded:", math.ceil(n - 0.5))
    


print("""Hi! Please choose an action:
1. Create a list.
2. Check file extension.
3. Solve the equation of n + nn + nnn + nnnn.
4. Difference between two dates.
5. Calculate i/2 * j^2 - k = m.
6. Display a string n times.
7. Check if number is even or odd.
8. Check wich values of one list are not in a different list.
9. Round a number.
10. Round a number using bankers rounding.
0. Exit.""")



while True:
    action = input()

    match action:
        case "1":
            create_list()
        case "2":
            check_file()
        case "3":
            calculate_nnnn()
        case "4":
            two_dates()
        case "5":
            calculate_equation()
        case "6":
            display_string()
        case "7":
            even_odd()
        case "8":
            list_compare()
        case "9":
            classic_rounding()
        case "10":
            n = float(input("Choose a number:"))
            print("Your number rounded:", round(n))
        case _:
            break
        
    print("Choose another action:")

    