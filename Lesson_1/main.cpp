//Libraries
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

//Function declaration
float radius, area;
void version_print();
void time_print();
void hello_world();
float circle_area_calculator(float radius);
void reverse_name();

int main() {
    
    version_print();
    time_print();
    hello_world();
    std::cout << "Circle Area Calculator: \nPlease enter the radius of a circle in centimetres " << std::endl;
    std::cin >> radius;
    area = circle_area_calculator(radius);
    std::cout << "The area of circle with ur radius is exactly " << area << "cm^2" << std::endl;
    reverse_name();
    return 0;
}


//Function definition
void version_print() {
    std::cout << "Compiler version: " << _MSC_VER << std::endl;
    
}

void time_print() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int min = localTime->tm_min;
    int sec = localTime->tm_sec;
    
    //Format the time as "HH:MM:SS"
    std::ostringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << hour << ":" <<
                  std::setw(2) << std::setfill('0') << min << ":" <<
                  std::setw(2) << std::setfill('0') << sec;
    std::string formattedTime = timeStream.str();


    //Format the date as "DD.MM.YYYY"
    std::ostringstream dateStream;
    dateStream << std::setw(2) << std::setfill('0') << day << "." <<
                  std::setw(2) << std::setfill('0') << month << "." <<
                  year;
     std::string forrmattedDate = dateStream.str();
     std::cout << "Time: " << formattedTime << " and Date: " << forrmattedDate << std::endl;
}
void hello_world() {
    std::cout << "Hello world :3 " << std::endl;
}

float circle_area_calculator(float radius) {
    float area;
    area = radius * radius * 22 / 7;
    return area;
}

void reverse_name() {
    std::string first, last;
    std::cout << "Please enter your first name" << std::endl;
    std::cin >> first;
    std::cout << "Please enter your last name" << std::endl;
    std::cin >> last;
    std::cout << "Hello there, user : " << last << " " << first << "\nGreat to see you using my software !!!" << std::endl;
}