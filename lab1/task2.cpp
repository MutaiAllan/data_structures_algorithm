#include <iostream>
#include <stdio.h>
#include <string.h>


struct Course;
struct Grade;

struct Course {
    char course_code[10];
    char course_name[50];
};



struct Grade {
    int mark;
    char the_grade;
    
    Grade(int m) : mark(m) {
        if (mark < 0 || mark > 100) {
            std::cerr << "Error: Mark must be between 0 and 100!" << std::endl;
            exit(1);
        }
    }
};


// student details
// Student details
struct Student {
    char reg_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grade;

    // Default constructor
    Student() : age(0), grade(0) {
        strcpy(reg_number, "");
        strcpy(name, "");
        strcpy(course.course_code, "");
        strcpy(course.course_name, "");
    }
    
    // Constructor with arguments
    Student(const char* reg, const char* n, int a, const char* code, const char* cname, int mark)
        : age(a), grade(mark) {
        strncpy(reg_number, reg, sizeof(reg_number));
        strncpy(name, n, sizeof(name));
        strncpy(course.course_code, code, sizeof(course.course_code));
        strncpy(course.course_name, cname, sizeof(course.course_name));
    }
};





// Generate grades
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

// Add at most 40 students
void addStudent(struct Student students[], int* numStudents) {
    if (*numStudents < 40) {
        char reg_number[20];
        char name[50];
        int age;
        char course_code[10];
        char course_name[50];
        int mark;

        printf("Enter student's registration number: ");
        scanf("%s", reg_number);

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter course code: ");
        scanf("%s", course_code);

        printf("Enter course name: ");
        scanf("%s", course_name);

        printf("Enter marks: ");
        scanf("%d", &mark);

        students[*numStudents] = Student(reg_number, name, age, course_code, course_name, mark);
        (*numStudents)++;

        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached!\n");
    }
}

//Edit students details
void editStudent(struct Student students[], int numStudents) {
    char regNumber[20];
    printf("Enter student's registration number: ");
    scanf("%s", regNumber);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            printf("Enter age: ");
            scanf("%d", &students[i].age);

            printf("Enter course code: ");
            scanf("%s", students[i].course.course_code);

            printf("Enter course name: ");
            scanf("%s", students[i].course.course_name);

            printf("Student details updated successfully!\n");
            return;
        }
    }

    printf("Registration number  not found\n");
}

// Add marks and calvulate grades
void addMarks(struct Student students[], int numStudents) {
    char regNumber[20];
    printf("Enter student's registration number: ");
    scanf("%s", regNumber);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].reg_number, regNumber) == 0) {
            printf("Enter marks: ");
            scanf("%d", &students[i].grade.mark);

            students[i].grade.the_grade = calculateGrade(students[i].grade.mark);

            printf("Marks and grade added successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}


int main() {
    struct Student students[40];
    for (int i = 0; i < 40; ++i) {
        // Initialize each student with default values
        students[i] = Student("", "", 0, "", "", 0);
    }
    int numStudents = 0;
    int choice;

    // Display menu
    printf("Enter an Option:\n");
    printf("1. Add a student\n");
    printf("2. Edit student's details\n");
    printf("3. Add marks and calculate grades\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addStudent(students, &numStudents);
            break;
        case 2:
            editStudent(students, numStudents);
            break;
        case 3:
            addMarks(students, numStudents);
            break;
        case 4:
            printf("Closing the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

