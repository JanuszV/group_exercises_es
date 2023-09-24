import Dates

println("Hi! Please choose an action:
1. Create a list.
2. Check file extension.
3. Solve the equation of n + nn + nnn + nnnn.
4. Difference between two dates.
5. Calculate i/2 * j^2 - k = m.
6. Display a string n times.
7. Check if number is even or odd.
8. Check wich values of one array are not in a different array.
9. Round a number.
10. Round a number using bankers rounding.
0. Exit.")
action = readline()
action = parse(Int64, action) 

function create_list()
    println("Please input the values of the list separated by a coma:")
    comma_values = readline()
    comma_array = split(comma_values, ",")
    println(comma_array)
end

function file_extensions()
    println("Please enter the name of the file:")
    file_name = readline()
    files = readdir()
    extensions = String[]
    for file in files
        separated_file = split(file, ".")
        if length(separated_file) > 1 && separated_file[1] == file_name
            push!(extensions, separated_file[2])
        end
    end
    println(extensions)
end

function calculate_nnn()
    println("How much is n:")
    n = readline()
    solution = parse(Int64, n) + parse(Int64, n*n) + parse(Int64, n*n*n) + parse(Int64, n*n*n*n)
    println(solution)
end

function two_dates()
    date_one = Dates.Date(2023, 1, 29)
    date_two = Dates.Date(2012, 5, 13)
    difference = date_one - date_two
    println(difference)
end

function calculate_equation()
    println("Input i:")
    i = readline()
    i = parse(Int64, i) 
    
    println("Input j:")
    j = readline()
    j = parse(Int64, j) 
    
    println("Input k:")
    k = readline()
    k = parse(Int64, k) 
    
    m = i/2 * j^2 - k
    if i == j && j == k
        m *= 3
    end
    print("i/2 * j^2 - k = ", m )
end

function display_string()
    println("Input a string:")
    input_string = readline()
    println("Choose n:")
    n = readline()
    n = parse(Int64, n)

    if length(input_string) < 2
        println(input_string ^ n)
    end
    println(input_string ^ n)
end

function even_odd()
    println("Choose a number:")
    n = readline()
    n = parse(Int64, n)
    if n % 2 == 0
        println("Your number is even")
    else
        println("Your number is odd")
    end

end

function array_compare()
    array_a = ["apple", "banana", "orange", "grape"]
    array_b = ["banana", "kiwi", "grape"]
    array_diff = setdiff(array_a, array_b)
    println(array_diff)
end

if action == 1
    create_list()
elseif action == 2
    file_extensions()
elseif action == 3
    calculate_nnn()
elseif action == 4
    two_dates()
elseif action == 5
    calculate_equation()
elseif action == 6
    display_string()
elseif action == 7
    even_odd()
elseif action == 8
    array_compare()
elseif action == 9
    println("Choose a number:")
    n = readline()
    n = parse(Float32, n)
    println(n, " rounds to ", round(n, RoundNearestTiesAway))
elseif action == 10
    println("Choose a number:")
    n = readline()
    n = parse(Float32, n)
    println(n, " rounds to ", round(n))
else
    println("Bye!")
end


