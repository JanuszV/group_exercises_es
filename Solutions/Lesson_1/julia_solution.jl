import Dates

println("Hi! Please choose an action:
1. Display Julia version.
2. Display the current time and date.
3. I want to see a rainbow colored \"Hello, World!\"!
4. Calculate the area of a circle using a user-provided radius as input.
5. Take user inputs for their first and last names, then reverse the order of the names, add a space between them, and display the result as a single output.
0. Exit.")
action = readline()
action = parse(Int64, action) 

function hello_world()
    #= orange, indigo and violet aren't supported with printstyled
    for color in [:red, :cyan, :blue, :magenta]
        printstyled("Hello World $(color)\n"; color = color)
    end
    =#
    colors = ["\033[0;31m", "\033[38;5;208m", "\033[1;33m", "\033[0;32m", "\033[0;36m", "\033[0;34m", "\033[0;35m"]
    index = 1
    text = "Hello, World!!!"
    for letter in text
        print(colors[index], letter, "\033[0m")
        index += 1
        if index > 7
            index = 1
        end
    end
    print("\n")
end

function circle_area(radius)
    area = radius ^ 2 * pi
    println("The area of a circle with radius of ", radius, " is equal to: ", area)
end

if action == 1
    println("Julia version: ", VERSION)
elseif action == 2
    println("Current time and date: ",Dates.DateTime(Dates.now()))
elseif action == 3
    hello_world()
elseif action == 4
    print("Enter the radius of the circle: ")
    radius = readline()
    radius = parse(Int64, radius)
    circle_area(radius) 
elseif action == 5
    print("Enter your first name: ")
    first = readline()
    print("Enter your last name: ")
    last = readline()
    println("Hello there, ", last, " ", first)
else
    println("Bye!")
end


