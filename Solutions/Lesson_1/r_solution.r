library(crayon)

print(paste("The R version you are using: ", R.version.string))

print(paste("The current time and date: ", Sys.time()))

hello_world()

radius <- as.numeric(readline("Enter the radius of the circle: "))
area <- circle_area(radius)
cat("The area of the circle with a radius of",
    radius, "is equal to", area, "\n")

name_switch()

hello_world <- function() {
  reset <- "\033[0m"
  red <- "\033[31m"
  orange <- "\033[38;5;202m"
  yellow <- "\033[33m"
  green <- "\033[32m"
  blue <- "\033[34m"
  indigo <- "\033[38;5;69m"
  violet <- "\033[38;5;129m"

  cat(paste0(red, "H", orange, "e", yellow, "l", green, "l",
            blue, "o", indigo, ", ", violet, "W", red, "o", orange,
            "r", yellow, "l", green, "d", blue, "!", reset, "\n"))
}

circle_area <- function(radius) {
  area <- pi * radius^2
  return(area)
}

name_switch <- function(){
  first <- readline("Enter your first name: ")
  last <- readline("Enter last name: ")

  cat("Hello there,", last, first, "\n")
}
