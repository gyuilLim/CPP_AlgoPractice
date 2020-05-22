/*#include <iostream>
#include <algorithm>
using namespace std;

void sort_three (int &a, int &b, int &c);

int main() {
   int i1 = 100, i2 = 90, i3 = 500;
   sort_three(i1,i2,i3);
   
   cout << "Three numbers are : " << i1 << "," << i2 << "," << i3 << endl;

   return 0;
}

void sort_three (int &a, int &b, int &c){
   int num1 = a;
   int num2 = b;
   int num3 = c;
   int list[3] = {num1, num2, num3};
   sort(list, list+3);
   a = list[0];
   b = list[1];
   c = list[2];
}*/
#include <iostream>
using namespace std;

void fillArray(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[5];
    fillArray(arr, 5);

    return 0;
}

void fiilArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "Put Array elements : ";
        cin >> arr[i];
    }
}

void printArray(int arr[], int n){
    cout << "Array elements are ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}