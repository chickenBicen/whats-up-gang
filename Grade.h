#ifndef GRADE_H  // Use #ifndef to check if the macro is defined
#define GRADE_H  // Define the macro to prevent multiple inclusions

#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <string>

// Avoid using namespace std in header files, prefer to use std:: explicitly
class Grade {
private:
    double value;

public:
    Grade() : value(0) {}  // Constructor with an initializer list

    Grade(double value) : value(value) {}  // Constructor with parameter

    void setValue(double value) {
        this->value = value;
    }

    std::string getLetterGrade() const {
        if (value >= 90) {
            return "A";
        } else if (value >= 80) {
            return "B";
        } else if (value >= 70) {
            return "C";
        } else if (value >= 60) {
            return "D";
        } else {
            return "F";
        }
    }

    double getValue() const {
        return value;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << value << " " << getLetterGrade();  // Add space between value and letter grade
        return ss.str();
    }
};

#endif  // End the include guard
