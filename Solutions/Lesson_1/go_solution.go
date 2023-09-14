package main

import (
	"fmt"
	"runtime"
	"time"
	"math"
)

func main() {
    print_version()
	time_date()
	hello_world()
	circle_area()
	reverse_name()
}

func print_version(){
	fmt.Println("Go version: ", runtime.Version())
}

func time_date(){
	fmt.Println("Right now it is: ", time.Now())
}

func hello_world(){
	reset := "\033[0m"

    red := "\033[31m"
	orange := "\033[38;5;202m"
    yellow := "\033[33m"
    green := "\033[32m"
    blue := "\033[34m"
    indigo := "\033[38;5;69m"
    violet := "\033[38;5;129m"
	fmt.Println(red, "H", orange, "e", yellow, "l", green, "l", blue, "o", indigo, violet, "W", red, "o", orange, "r", yellow, "l", green, "d", blue, "!", reset);
}

func circle_area(){
	var radius float64

	fmt.Print("Input the value of the radius: ")
	fmt.Scan(&radius)

	area := math.Pow(radius, 2) * math.Pi
	fmt.Println("The area of a circle with this radius is equal to: ", area)
}

func reverse_name(){
	var first string
	var last string
	
	fmt.Print("What's your first name?: ")
	fmt.Scan(&first)

	fmt.Print("What's your last name?: ")
	fmt.Scan(&last)

	fmt.Println("Hello there,", last, first, "!")
}
