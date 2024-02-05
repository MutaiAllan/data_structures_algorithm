#include <iostream>
#include <string>

class Course {
public:
    std::string course_code;
    std::string course_name;
};

class Grade {
public:
    int mark;
    char the_grade;
    
    Grade(int m) : mark(m) {
        if (mark < 0 || mark > 100) {
            std::cerr << "Error: Mark must be between 0 and 100!" << std::endl;
            exit(1);
        }
    }
};

class Student {
public:
    std::string reg_number;
    std::string name;
    int age;
    Course course;
    Grade grade;

    // Default constructor
    Student() : age(0), grade(0) {}
    
    // Constructor with arguments
    Student(const std::string& reg, const std::string& n, int a, const std::string& code, const std::string& cname, int mark)
        : reg_number(reg), name(n), age(a), course{code, cname}, grade(mark) {}
};

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

void addStudent(Student students[], int& numStudents) {
    if (numStudents < 40) {
        std::string reg_number;
        std::string name;
        int age;
        std::string course_code;
        std::string course_name;
        int mark;

        std::cout << "Enter student's registration number: ";
        std::cin >> reg_number;

        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter age: ";
        std::cin >> age;

        std::cout << "Enter course code: ";
        std::cin >> course_code;

        std::cout << "Enter course name: ";
        std::cin >> course_name;

        std::cout << "Enter marks: ";
        std::cin >> mark;

        students[numStudents] = Student(reg_number, name, age, course_code, course_name, mark);
        numStudents++;

        std::cout << "Student added successfully!" << std::endl;
    } else {
        std::cout << "Maximum number of students reached!" << std::endl;
    }
}

void editStudent(Student students[], int numStudents) {
    std::string regNumber;
    std::cout << "Enter student's registration number: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].reg_number == regNumber) {
            std::cout << "Enter age: ";
            std::cin >> students[i].age;

            std::cout << "Enter course code: ";
            std::cin >> students[i].course.course_code;

            std::cout << "Enter course name: ";
            std::cin >> students[i].course.course_name;

            std::cout << "Student details updated successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Registration number not found" << std::endl;
}

void addMarks(Student students[], int numStudents) {
    std::string regNumber;
    std::cout << "Enter student's registration number: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].reg_number == regNumber) {
            std::cout << "Enter marks: ";
            std::cin >> students[i].grade.mark;

            students[i].grade.the_grade = calculateGrade(students[i].grade.mark);

            std::cout << "Marks and grade added successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Student not found!" << std::endl;
}

void displayStudents(const Student students[], int numStudents) {

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Student " << i + 1 << ":" << std::endl;
        std::cout << "Registration Number: " << students[i].reg_number << std::endl;
        std::cout << "Name: " << students[i].name << std::endl;
        std::cout << "Age: " << students[i].age << std::endl;
        std::cout << "Course Code: " << students[i].course.course_code << std::endl;
        std::cout << "Course Name: " << students[i].course.course_name << std::endl;
        std::cout << "Mark: " << students[i].grade.mark << std::endl;
        std::cout << "Grade: " << students[i].grade.the_grade << std::endl;
        std::cout << std::endl;
    }
}


int main() {
    Student students[40];
    int numStudents = 0;
    int choice;

    // Display menu
    std::cout << "Enter an Option:" << std::endl;
    std::cout << "1. Add a student" << std::endl;
    std::cout << "2. Edit student's details" << std::endl;
    std::cout << "3. Add marks and calculate grades" << std::endl;
    std::cout << "4. Display students" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            addStudent(students, numStudents);
            break;
        case 2:
            editStudent(students, numStudents);
            break;
        case 3:
            addMarks(students, numStudents);
            break;
        case 4:
            displayStudents(students, numStudents);
            break;
        case 5:
            std::cout << "Closing the program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }

    return 0;
}
