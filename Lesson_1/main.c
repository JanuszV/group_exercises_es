#include <stdio.h>
#include <time.h>

void version_print();
void time_print();
void hello_world();
float circle_area_calculator(float radius);
void reverse_name();

int main() {
    float radius, area;
    version_print();
    time_print();
    hello_world();
    printf("Circle Area Calculator --- Enter radius of your circle\n");
    scanf("%f", &radius);
    area = circle_area_calculator(radius);
    printf("Circle Area is equal to %f cm^2\n", area);
    reverse_name();
    return 0;
}

void version_print() {
    printf("Compiler version: %ld\n", _MSC_VER);
}

void time_print() {
    time_t currentTime;
    struct tm *ptr;

    // Get the current time
    time(&currentTime);
    ptr = localtime(&currentTime);

    // Print the formatted date and time
    printf("Current date and time: %s", asctime(ptr));
}

void hello_world() {
    printf("Hello world \n");
}

float circle_area_calculator(float radius) {
    float area;
    area = radius * radius * 22 / 7;
    return area;
}
void reverse_name() {
    char first[50], last[50];
    printf("Enter your first name : \n");
    scanf("%s", first);
    printf("Enter your last name : \n");
    scanf("%s", last);
    printf("%s %s", last, first);
    printf("\nThank you for using my software");
}