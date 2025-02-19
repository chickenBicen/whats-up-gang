#include <sstream>
#include <string>
#include <vector>
#include <array>
#include "Grade.h"

using namespace std;

class Grades{
    private:
        vector<Grade> grades;
    
    public:
        Grades() : grades() {}

        Grades(std::string gradeList){
            stringstream ss(gradeList);
            string grade;
            while(getline(ss, grade, ' ')){
                double value = stod(grade);
                Grade g(value);
                grades.push_back(g);
            }
        }

        vector<Grade> getGrades() const {
            return grades;
        }

        void addGrade(double gradeValue){
            Grade grade(gradeValue);
            grades.push_back(grade);
        }

        void setGrade(int index, double gradeValue){
            grades[index].setValue(gradeValue);
        }

        double getSum() const {
            double sum = 0;
            for(Grade grade : grades){
                sum += grade.getValue();
            }
            return sum;
        }

        double getLowGrade() const {
            if (grades.empty()) return 0.0;
            double low = grades[0].getValue();
            for(Grade grade : grades){
                if(grade.getValue() < low){
                    low = grade.getValue();
                }
            }
            return low;
        }

        double getHighGrade() const {
            if (grades.empty()) return 0.0;
            double high = grades[0].getValue();
            for(Grade grade : grades){
                if(grade.getValue() > high){
                    high = grade.getValue();
                }
            }
            return high;
        }

        int getNumGrades() const {
            return grades.size();
        }

        std::string toString() const {
            stringstream ss;
            for(Grade grade : grades){
                ss << grade.toString() << " ";
            }
            return ss.str();
        }
};
