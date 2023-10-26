import os
import datetime
import math

def sort_three():
    i = int(input("Choose first number: "))
    j = int(input("Choose second number: "))
    k = int(input("Choose third number: "))
    
    print("Sorted numbers: {}, {}, {}.".format(min(i, j, k), i + j + k - min(i, j, k) - max(i, j, k), max(i, j, k)))


def print_vertically():
    n = int(input("Input an integer value: "))
    values = [[0 for _ in range(n)] for _ in range(len(str(n)))]
    for i in range(1, len(str(n))):
        for j in range(1, n):
            if len(str(j)) >= i:
                values[i][j] = str(j)[i - 1]
    print(values)
    
def print_vertically():
    n = int(input("Input an integer value: "))
    max_width = len(str(n))
    
    for i in range(max_width):
        for j in range(n + 1):
            if len(str(j)) >= max_width - i:
                digit = str(j)[-max_width + i]
                print(digit, end='\n' if j == n else ' ')
            else:
                print(' ', end=' ')

def perfect_square():
    n = int(input("Choose n:"))
    n_sqr = n*n
    n_sqr_rev = int(str(n_sqr)[::-1])
    n_rev_root = math.sqrt(n_sqr_rev)
    result = n_rev_root == int(n_rev_root)

    print("Is it a perfect square: ", result)

def translate():
    mode = int(input("""Do you want to translate (choose 1-3): 
                     1 - Decimal to binary and hexadecimal
                     2 - Binary to decimal and hexadecimal
                     3 - Hexadecimal to binary and decimal"""))
    i = input("Choose a number:")
    if mode == 1:
        print("{}, in binary = {} and in hexadecimal {}".format(int(i), bin(int(i)), hex(int(i))))
    elif mode == 2:
        print("{}, in decimal = {} and in hexadecimal {}".format(i, int(i, 2), hex(int(i, 2))))
    elif mode == 3:
        print("{}, in binary = {} and in decimal {}".format(i, bin(int(i, 16)), int(i, 16)))
    else: return
        

def check_n(n):
    for i in range(n * 2, 1000000, n):
        if str(i)[-1] == str(n) and i % n == 0 :
            return i
    return -1 
    
    


print("""Hi! Please choose an action:
1. Sort three integers without using loops, if statements, or built-in sort functions.
2. Print all numbers from 0 to n vertically.
3. Perfect square!
4. Translate between number systems.
5. Look for smalles positive integer which ends with n, is divisible by n, and the sum of its digits equals n.
0. Exit.""")



while True:
    action = input()

    match action:
        case "1":
            sort_three()
        case "2":
            print_vertically()
        case "3":
            perfect_square()
        case "4":
            translate()
        case "5":        
            n = int(input("Choose number:"))
            result_n = check_n(n)
            if result_n != -1:
                print(f"The smallest positive integer that ends with {n}, is divisible by {n} is: {result_n}")
            else:
                print("No such integer found within the search range.")
        case _:
            break
        
    print("Choose another action:")

    