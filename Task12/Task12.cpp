#include <iostream>
using namespace std;

struct CDAccountV1{
    double balance;
    double interestRate;
    int term;
};

void swap(CDAccountV1 &v1, CDAccountV1 &v2){
    double temp1, temp2;
    int temp3;
    temp1 = v1.balance;
    temp2 = v1.interestRate;
    temp3 = v1.term;
    v1.balance = v2.balance;
    v1.interestRate = v2.interestRate;
    v1.term = v2.term;
    v2.balance = temp1;
    v2.interestRate = temp2;
    v2.term = temp3;
}

int main() {
    CDAccountV1 v1 = {10.0, 0.01, 60};
    CDAccountV1 v2 = {50.0, 0.02, 30};

        swap (v1, v2);

    cout << "balance: " << v1.balance
            << " interest: " << v1.interestRate
            << " terms: " << v1.term << endl;

     cout << "balance: " << v2.balance
             << " interest: " << v2.interestRate
             << " terms: " << v2.term << endl;




    return 0;
}