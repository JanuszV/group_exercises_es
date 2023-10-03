#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <chrono>
#include <cmath>
#include <algorithm>


namespace fs = std::filesystem;

// Function to convert a comma-separated string of numbers into an array (used in first functionality)
std::vector<int> parseStringToArray(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);
    std::string number;

    while (std::getline(iss, number, ',')) {
        try {
            int num = std::stoi(number);
            result.push_back(num);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number: " << number << std::endl;
        }
    }

    return result;
}
// Function to convert a comma-separated string of numbers into an string array (used in eight functionality)
std::vector<std::string> parseStringToStringArray(const std::string& input) {
    std::vector<std::string> result;
    std::istringstream iss(input);
    std::string number;

    while (std::getline(iss, number, ',')) {
        try {
            result.push_back(number);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number: " << number << std::endl;
        }
    }

    return result;
}
void searchAndDisplayFiles(const std::string& searchString) {
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() || entry.is_directory()) {
            std::string entryName = entry.path().filename().string();
            if (entryName.find(searchString) != std::string::npos) {
                std::string information;
                information = entry.path().extension().string();
                if (information =="") {
                    information = "File is a directory";
                }
                
                std::cout << "File/Directory: " << entryName << ", Information: " << information << std::endl;
            }
            else{
            std::cout << "No file with that substring in name" << std::endl;
        }
        }
        
    }
}
int integerEquation(const std::string& intEquat){
    int value = 0;
    try {
        value = std::stoi(intEquat);
        std::cout << "The string represents an integer: " << value << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "The string is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "The string represents an integer, but it's out of range." << std::endl;
        
    }
   int suma = value + value*value + value*value*value + value*value*value*value;
   return suma;
}
// Function to convert a date string in DD.MM.YYYY format to a time_point
std::chrono::system_clock::time_point parseDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d.%m.%Y");
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    return tp;
}

// Function to calculate the number of days between two dates
int calculateDaysBetweenDates(const std::string& dateStr1, const std::string& dateStr2) {
    auto date1 = parseDate(dateStr1);
    auto date2 = parseDate(dateStr2);
    
    auto duration = date2 - date1;
    return std::chrono::duration_cast<std::chrono::hours>(duration).count() / 24;
}
void Funtion6(const std::string& word, const std::string& integer6){
    int integer6int = 0;
    try {
        integer6int = std::stoi(integer6);
    } catch (const std::invalid_argument& e) {
        std::cout << "Number is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "Number represents an integer, but it's out of range." << std::endl;
        
    }
    int length = word.length();
    if (length < 2){
        std::cout << word << std::endl;
        std::cout << word << std::endl;
        return;
    }
    for (int i = 0; i < integer6int; i++){
        std::cout << word << std::endl;
    }
}
void OddOrEven(void){
    std::string numberst;
    std::cout << "Enter number : ";
    std::cin >> numberst;
    int number = 0;
    try {
        number = std::stoi(numberst);
    } catch (const std::invalid_argument& e) {
        std::cout << "Number is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "Number represents an integer, but it's out of range." << std::endl;
        
    }
    int remainder = number % 2;
    if (remainder == 1){
        std::cout << "Your number is odd" << std::endl;
        return;
    }
    std::cout << "Your number is even" << std::endl;
    
}
float Function5(const std::string& i,const std::string& j,const std::string& k){
    int ii = 0, ij = 0, ik = 0;
    try {
        ii = std::stoi(i);
    } catch (const std::invalid_argument& e) {
        std::cout << "The string i is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "The string i represents an integer, but it's out of range." << std::endl;
        
    }
    try {
        ij = std::stoi(j);
        
    } catch (const std::invalid_argument& e) {
        std::cout << "The string j is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "The string j represents an integer, but it's out of range." << std::endl;
        
    }
    try {
        ik = std::stoi(k);
        
    } catch (const std::invalid_argument& e) {
        std::cout << "The string k is not an integer." << std::endl;
        
    } catch (const std::out_of_range& e) {
        std::cout << "The string k represents an integer, but it's out of range." << std::endl;
        
    }
    float iii = ii;
    float suma = (iii/2) * (ij*ij) - ik;
    if (ii == ij && ii == ik){
        suma = suma * 3;
    }
    return suma;
}
void comparingLists(const std::vector<std::string> list1, const std::vector<std::string> list2){
    std::cout << "Elements in list1 that are not in list2: ";
    for (const std::string& element : list1) {
        if (std::find(list2.begin(), list2.end(), element) == list2.end()) {
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;

    return;
}
int schoolRounding(const double number){
    int integerPart = std::floor(number);
    double decimalPart = number - integerPart;
    if (decimalPart >= 0.5){
        return integerPart + 1;
    }else {
        return integerPart;
    }

}

int main() {
    //1.......................//////////////////////
    std::string inputString;
    std::cout << "Enter comma-separated numbers: ";
    std::cin >> inputString;
    std::vector<int> numArray = parseStringToArray(inputString);
    std::cout << "Complete Array: [";
    for (size_t i = 0; i < numArray.size(); ++i) {
        std::cout << numArray[i];
        if (i < numArray.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    if (!numArray.empty()) {
        std::cout << "First Index Value: " << numArray.front() << std::endl;
        std::cout << "Last Index Value: " << numArray.back() << std::endl;
    } else {
        std::cout << "Array is empty." << std::endl;
    }
    //2.........................////////////////////////////////////////////
    std::string searchString;
    std::cout << "Enter a search string: ";
    std::cin >> searchString;
    searchAndDisplayFiles(searchString);
    //3.......................////////////////////////////////////////////
    std::string intEquation;
    std::cout << "Enter an integer for quation n + nn + nnn + nnnn = m : ";
    std::cin >> intEquation;
    int suma = integerEquation(intEquation);
    std::cout << "m is equal to : " << suma << std::endl;
    //4............................////////////////////////////////////
    std::string dateStr1, dateStr2;
    std::cout << "Enter the first date (DD.MM.YYYY): ";
    std::cin >> dateStr1;
    std::cout << "Enter the second date (DD.MM.YYYY): ";
    std::cin >> dateStr2;
    int daysBetween = calculateDaysBetweenDates(dateStr1, dateStr2);
    std::cout << "Number of days between the two dates: " << daysBetween << std::endl;
    // 5.................../////////////////////////////////////////////////
    std::string i,j,k;
    std::cout << "Enter integer for equation i/2 * j^2 - k = m" << std::endl;
    std::cout << "Enter integer i : ";
    std::cin >> i;
    std::cout << "Enter integer j : ";
    std::cin >> j;
    std::cout << "Enter integer k : ";
    std::cin >> k;
    float wynik = Function5(i,j,k);
    std::cout << "The result of the equation m is equal to : " << wynik << std::endl;
    // 6.....///////////////////////////////////////////////////////////////
    std::string word, number;
    std::cout << "Enter string : ";
    std::cin >> word;
    std::cout << "Enter integer : ";
    std::cin >> number;
    Funtion6(word,number);
    //7......................................................//////////////////
    OddOrEven();
    //8......................................................////////////////////////
    std::string slist1, slist2;
    std::cout << "Enter comma-separated element for first list : ";
    std::cin >> slist1;
    std::cout << "Enter comma-separated element for second list : ";
    std::cin >> slist2;
    std::vector<std::string> list1 = parseStringToStringArray(slist1);
    std::vector<std::string> list2 = parseStringToStringArray(slist2);
    comparingLists(list1, list2);
    //9.....................................................//////////////////////////////
    double nr;
    std::cout << "Enter your number : ";
    std::cin >> nr;
    std::cout << "Rounded your number to :" << schoolRounding(nr) << std::endl;
    //10...................................................//////////////////////////////
    double nr10;
    std::cout << "Enter your number : ";
    std::cin >> nr10;
    std::cout << "Banking rounded your number to :" << std::round(nr10) << std::endl;
    return 0;
}