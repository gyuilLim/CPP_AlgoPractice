#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class DayOfYear{
    public:
        DayOfYear(string sMonth, int dayValue);

        DayOfYear(string sMonth);

        DayOfYear();

        void input();
        void output();
        int getMonthNumber();
    private:
        string month;
        int day;
        void testDate();
};

int main() {
    string sMonth;
    int day;
    cout << "Put an abbreviation of a month (3 chars) and a day (number) : ";
    cin >> sMonth >> day;
    DayOfYear date1(sMonth), date2(sMonth, day);
    date1.output();
    date2.output();

    return 0;
}

DayOfYear::DayOfYear(string sMonth, int dayValue)
:month(sMonth), day(dayValue){
    testDate();
}

DayOfYear::DayOfYear(string sMonth) : month(sMonth), day(1){
    testDate();
}

DayOfYear::DayOfYear() : month("Jan"), day(1){}

void DayOfYear::testDate(){
    if (getMonthNumber() < 1 || getMonthNumber() > 12){
        cout << "Illegal month value!\n";
        exit(1);
    }
    if (day < 1 || day > 31){
        cout << "Illegal day value!\n";
        exit(1);
    }
}

void DayOfYear::output(){
    switch (getMonthNumber()){
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
    cout << day << endl;
}

int DayOfYear::getMonthNumber(){
    if (month == "Jan") return 1;
    else if (month == "Feb") return 2;
    else if (month == "Mar") return 3;
    else if (month == "Apr") return 4;
    else if (month == "May") return 5;
    else if (month == "Jun") return 6;
    else if (month == "Jul") return 7;
    else if (month == "Aug") return 8;
    else if (month == "Sep") return 9;
    else if (month == "Oct") return 10;
    else if (month == "Nov") return 11;
    else if (month == "Dec") return 12;
}