#include <iostream>
using namespace std;

int main() {
    double cel;
    cout << "Put the degree in Celsius : ";
    cin >> cel;

    double fah = 1.8 * cel + 32;

    cout << "The degree in Fahrenheit is " << fah << endl;


    return 0;
}