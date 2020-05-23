#include <iostream>
#include <string>
using namespace std;

class Employee{
    public:
        Employee();
        Employee(const string& theName, const string& theSsn);
        string getName() const;
        string getSsn() const;
        double getNetPay() const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);
        void printCheck() const;
    private:
        string name;
        string ssn;
        double netPay;
};

Employee::Employee() : name("No name Yet"), ssn("No number yet"), netPay(0){}
Employee::Employee(const string& theName, const string& theNumber) : name(theName), ssn(theNumber), netPay(0){}
string Employee::getName() const {return name;}
string Employee::getSsn() const {return ssn;}
double Employee::getNetPay() const {return netPay;}
void Employee::setName(const string& newName){name = newName;}
void Employee::setSsn(const string& newSsn){ssn = newSsn;}
void Employee::setNetPay(double newNetPay){netPay = newNetPay;}
void Employee::printCheck() const{
    cout << "\nError : printCheck FUNCTION CALLED FOR AN \n"
         << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
         << "Check with the author of the program about this bug.\n";
    exit(1);
}

class HourlyEmployee : public Employee{
    public:
        HourlyEmployee();
        HourlyEmployee(const string& theName, const string& theSsn, double theWageRate, double theHours);
        void setRate(double newWageRate);
        double getRate() const;
        void setHours(double hoursWorked);
        double getHours() const;
        void printCheck();
    private:
        double wageRate;
        double hours;
};

HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0){}
HourlyEmployee::HourlyEmployee(const string& theName, const string& theNumber, double theWageRate, double theHours)
: Employee(theName, theNumber), wageRate(theWageRate), hours(theHours){}
void HourlyEmployee::setRate(double newWageRate){wageRate = newWageRate;}
double HourlyEmployee::getRate() const {return wageRate;}
void HourlyEmployee::setHours(double hoursWorked){hours = hoursWorked;}
double HourlyEmployee::getHours() const {return hours;}

void HourlyEmployee::printCheck(){
    setNetPay(hours * wageRate);
    cout << "\n_________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << "Dollars\n";
    cout << "________________________________________\n";
    cout << "Check Stub : NOT NEGETIABLE\n";
    cout << "Employee Number : " << getSsn() << endl;
    cout << "Hourly Employee. \nHours worked : " << hours
         << " Rate : " << wageRate << " Pay : " << getNetPay() << endl;
    cout << "_____________________________________________\n";
}

class UinvHourlyEmployee : public HourlyEmployee{
    public:
        UinvHourlyEmployee();
        UinvHourlyEmployee(const string& theName, const string& theSsn, const string& univName, double theWageRate, double theHours);
        void setUinvName(const string& newUinvName);
        string getUinvName() const ;
        void printinfo();
    private:
        string univName;
};

UinvHourlyEmployee::UinvHourlyEmployee(const string& theName, const string& theNumber, const string& theUnivName, double theWageRate, double theHours)
: HourlyEmployee(theName, theNumber, theWageRate, theHours), univName(theUnivName){}
void UinvHourlyEmployee::setUinvName(const string& newUinvName){univName = newUinvName;}
string UinvHourlyEmployee::getUinvName() const {return univName;}
void UinvHourlyEmployee::printinfo(){
    cout << "Employee Name : " << getName() << " Affliation : " << getUinvName() << endl;
    printCheck();
}

int main() {
    UinvHourlyEmployee john("JohnDoe", "123456", "SSU", 10, 40);
    john.printinfo();

    return 0;
}