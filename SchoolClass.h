#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include "Student.h"

class SchoolClass {
    private:
        std::string name;
        std::vector<Student> students;
    
    public:
        SchoolClass() : name(""), students() {}

        SchoolClass(std::string name) : name(name), students() {}

        std::vector<Student> getStudents() const {
            return students;
        }

        void sortStudents() {
            int n = students.size();
            Student temp;
            for (int i = 0; i < n - 1; i++) {
                bool swapped = false;
                for (int j = 0; j < n - i - 1; j++) {
                    if (students[j].compareTo(students[j + 1]) > 0) {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                        swapped = true;
                    }
                }

                if (!swapped) {
                    break;
                }
            }
        }

        void addStudent(Student student) {
            students.push_back(student);
        }

        double getClassAverage() const {
            double sum = 0;
            for (Student student : students) {
                sum += student.getAverage();
            }
            return sum / students.size();
        }

        double getStudentAverage(std::string studentName) const {
            for (Student student : students) {
                if (student.getName() == studentName) {
                    return student.getAverage();
                }
            }
            return 0.0;
        }

        double getStudentWithHighestAverage() const {
            double high = 0;
            for (Student student : students) {
                double avg = student.getAverage();
                if (avg > high) {
                    high = avg;
                }
            }
            return high;
        }

        double getStudentWithLowestAverage() const {
            double low = 100;
            for (Student student : students) {
                double avg = student.getAverage();
                if (avg < low) {
                    low = avg;
                }
            }
            return low;
        }

        std::string getFailures(double failingGrade) const {
            std::stringstream ss;
            for (Student student : students) {
                if (student.getAverage() < failingGrade) {
                    ss << student.getName() << " ";
                }
            }
            return ss.str();
        }

        std::string toString() const {
            return name + "\n";
        }
};

#endif