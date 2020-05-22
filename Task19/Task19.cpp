#include <iostream>
using namespace std;

int* allocArray(int size);
void printArray(int* array, int size);
void freeArray(int* array);

int main() {
    int *arr;
    int size;

    cout << "Enter the array size : ";
    cin >> size;
    arr = allocArray(size);

    for (int i = 0; i < size; i++){
        cout << "Put an array element : ";
        cin >> arr[i];
    }

    printArray(arr, size);
    freeArray(arr);

    return 0;
}

int* allocArray(int size){
    int* array;
    array = new int[size];
    return array;
}

void printArray(int* array, int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}

void freeArray(int* arr){
    delete [] arr;
}