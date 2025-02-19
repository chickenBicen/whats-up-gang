#include <iostream>
#include "Student.h"
#include "SchoolClass.h"

int main() {
    // Create students
    Student student1("Alice", "85 90 78");
    Student student2("Bob", "88 92 79");
    Student student3("Charlie", "70 75 80");

    // Print student details
    std::cout << "Student 1: " << student1.toString() << std::endl;
    std::cout << "Student 2: " << student2.toString() << std::endl;
    std::cout << "Student 3: " << student3.toString() << std::endl;

    // Create a school class and add students
    SchoolClass schoolClass("Math 101");
    schoolClass.addStudent(student1);
    schoolClass.addStudent(student2);
    schoolClass.addStudent(student3);

    // Print class average
    std::cout << "Class Average: " << schoolClass.getClassAverage() << std::endl;

    // Print student with highest and lowest average
    std::cout << "Highest Average: " << schoolClass.getStudentWithHighestAverage() << std::endl;
    std::cout << "Lowest Average: " << schoolClass.getStudentWithLowestAverage() << std::endl;

    // Print students who are failing
    std::cout << "Failing Students: " << schoolClass.getFailures(75) << std::endl;

    // Sort students and print sorted list
    schoolClass.sortStudents();
    std::cout << "Sorted Students: " << std::endl;
    for (Student student : schoolClass.getStudents()) {
        std::cout << student.toString() << std::endl;
    }

    return 0;
}
