import sys
import datetime
def version_print():
    print(f"Python Version:{sys.version_info.major}.{sys.version_info.minor}.{sys.version_info.micro}")

def time_print():
    currentTime = datetime.datetime.now().time()
    formatted_time = currentTime.strftime("%H:%M:%S")
    current_date = datetime.datetime.now().date()
    formatted_date = current_date.strftime("%d.%m.%Y")
    print(f"Time : {formatted_time} and Date : {formatted_date} r.")

def hello_world():
    print("Hello world")

def circle_area_calculator(radius):
    area = radius * radius * 22 / 7
    return area
def reverse_name():
    first = input("Enter your first name:\n")
    last = input("Enter your last name:\n")
    print("{} {}".format(last, first))
def main():
    version_print()
    time_print()
    hello_world()
    user_input = input("Circle Area Calculator: Enter your circle radius:\n")
    radius = int(user_input)
    area = circle_area_calculator(radius)
    print(f"Area of entered circle is : {area} cm^2")
    reverse_name()

if __name__ == "__main__":
    main()