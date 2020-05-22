#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[4][4] = {10, 20, 30, 40, 5, 4, 3, 99, 55, 100, 42, 100, 0, 105, 2, 11};

    int first, second;
    
    first = a[0][0];
    second = a[0][0];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (first < a[i][j]){
                first = a[i][j];
            }
            else if (second < a[i][j]){
                second = a[i][j];
            }
        }
    }

    cout << "The largest number is " << first << endl;
    cout << "The second-largest number is " << second << endl;

    return 0;
}