#include <iostream>
using namespace std;

void fillArray(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int arr[5];
    fillArray(arr, 5);
    printArray(arr, 5);
    return 0;
}

void fillArray(int arr[], int n){
    cout << "Put array elements : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void printArray(int arr[], int n){
    cout << "Array elements are ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}