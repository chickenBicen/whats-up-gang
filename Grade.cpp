#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class Grade {
    private:
        double value;

    public:
        Grade(){
            value = 0;
        }

        Grade(double value){
            this->value = value;
        }

        void setValue(double value){
            this->value = value;
        }

        string getLetterGrade(){
            if(value >= 90){
                return "A";
            } else if(value >= 80){
                return "B";
            } else if(value >= 70){
                return "C";
            } else if(value >= 60){
                return "D";
            } else {
                return "F";
            }
        }

        double getValue(){
            return value;
        }

        string toString(){
            stringstream ss;
            ss << value << getLetterGrade();
            return ss.str();
        }
};
