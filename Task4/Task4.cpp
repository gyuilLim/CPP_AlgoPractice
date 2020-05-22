#include <iostream>
#include <string>
using namespace std;

int main() {
    double discrete, programming, data;

    cout << "Put the discrete math score : ";
    cin >> discrete;

    cout << "Put the programming language score : ";
    cin >> programming;

    cout << "Put the data structure score : ";
    cin >> data;

    double avg = (discrete + programming + data) / 3;
    string grade;

    if (avg > 95){
        grade = "A+";
    }
    else {
        if (avg > 90){
            grade = "A0";
        }
        else {
            if (avg > 85){
                grade = "B+";
            }
            else{
                if (avg > 80){
                    grade = "B0";
                }
                else{
                    if (avg > 75) {
                        grade = "C+";
                    }
                    else {
                        if (avg > 70){
                            grade = "C0";
                        }
                        else {
                            grade = "F";
                        }
                    }
                }
            }
        }
    }
    

    cout << "The avarage score is " << avg << " and the grade is " << grade << endl;

    return 0;
}