#include <iostream>
using namespace std;

class DayofYear{
    public:
        int month;
        int day;
        void adjustDay(int a);
        void output();
};

int main() {
    DayofYear d1;
    d1.month = 8;
    d1.day = 20;

    d1.adjustDay(20);
    d1.output();

    return 0;
}

void DayofYear::adjustDay(int a){
    day = day + a; //day = 0 month = 3
    if (day < 1) {
        while (day < 1){
            switch(month){
                case 1:
                    month = 12;
                    day += 31;
                    break;
                case 2:
                case 4:
                case 6:
                case 8:
                case 9:
                case 11:
                    month -= 1;
                    day += 31;
                    break;
                case 3:
                    month -= 1;
                    day += 28;
                    break;
                case 5:
                case 7:
                case 10:
                case 12:
                    month -= 1;
                    day += 30;
                    break;
            }
        }
    }
    else {
        while (day > 28){
            if (month == 1 || month == 3 || month == 5 || 
                month == 7 || month == 8 || month == 10 || 
                month == 12){
                if (day > 31){
                    month = month + (day/31);
                    day = day % 31;
                }
            }

            else if (month == 2){
                if (day > 28){
                    month = month + (day/28);
                    day = day % 28;
                }
            }

            else if (month == 4 || month == 6 || 
                     month == 9 || month == 11){
                if (day > 30){
                    month = month + (day/30);
                    day = day % 30;
                }
            }
            if (month > 12){
                month = month % 12;
            }
        }
    }
}

void DayofYear::output(){
    switch (month){
        case 1: 
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case  8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11: 
            cout << "November ";
            break;
        case 12:
            cout << "December ";
            break;
    }
    cout << day;
}