#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string str;
    fstream inputStream;

    inputStream.open("string.txt");

    while (!inputStream.eof()){
        inputStream >> str;
        if (str == "hate"){
            str = "love";
        }
        cout << str << " ";
    }

    inputStream.close();

    return 0;
}