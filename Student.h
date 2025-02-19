#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Grades.h"

class Student {
    private:
        std::string name;
        Grades grades;
    
    public:
        Student() : name(""), grades() {}

        Student(std::string name, std::string gradeList) : name(name), grades(gradeList) {}

        void setName(std::string name) {
            this->name = name;
        }

        void setGrades(std::string gradeList) {
            grades = Grades(gradeList);
        }

        void setGrade(int index, double gradeValue) {
            grades.setGrade(index, gradeValue);
        }

        std::string getName() const {
            return name;
        }

        int getNumGrades() const {
            return grades.getGrades().size();
        }

        double getSum() const {
            return grades.getSum();
        }

        double getAverage() const {
            int numGrades = getNumGrades();
            if (numGrades == 0) return 0.0;
            return getSum() / numGrades;
        }

        double getAverageNoLow() const {
            int numGrades = getNumGrades();
            if (numGrades <= 1) return 0.0;
            double low = grades.getLowGrade();
            double sum = getSum() - low;
            return sum / (numGrades - 1);
        }

        double getHighGrade() const {
            return grades.getHighGrade();
        }

        double getLowGrade() const {
            return grades.getLowGrade();
        }

        int compareTo(const Student& other) const {
            if (getAverage() < other.getAverage()) {
                return -1;
            } else if (getAverage() > other.getAverage()) {
                return 1;
            } else {
                return 0;
            }
        }

        std::string toString() const {
            std::stringstream ss;
            ss << name << " = " << grades.toString();
            return ss.str();
        }
};
#endif // STUDENT_H