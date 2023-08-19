#include <stdio.h>

// Nested structure to store date of birth
struct dob {
    int day;
    int month;
    int year;
};

// Structure to store student information
struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function using call-by-value to print student information
void printStudentByValue(struct student_info student) {
    printf("Call-by-value function:\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d-%d-%d\n", student.age.day, student.age.month, student.age.year);
}

// Function using call-by-address to print student information
void printStudentByAddress(struct student_info *student) {
    printf("\nCall-by-address function:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d-%d-%d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    // Create a student_info structure and populate its members
    struct student_info student;
    student.roll_no = 101;
    strcpy(student.name, "Sagnik Sen");
    student.CGPA = 7.73;
    student.age.day = 10;
    student.age.month = 7;
    student.age.year = 2002;

    // Print student information using call-by-value
    printStudentByValue(student);

    // Print student information using call-by-address
    printStudentByAddress(&student);

    return 0;
}
