#include <iostream>
using namespace std;

class A{
    public:
        int a;
        A(){
            cout << "Constructor in class A executed" << endl;
        }
        ~A(){
            cout << "Destructor in class A executed" << endl;
        }
};

class B : public A{
    public:
        int b;
        B(){
            cout << "Constructor in class B executed" << endl;
        }
        ~B(){
            cout << "Destructor in class B executed" << endl;
        }
};

class C : public B{
    public:
        int c;
        C(){
            cout << "Constructor in class C executed" << endl;
        }
        ~C() {
            cout << "Desturctor in class C executed" << endl;
        }
};

int main() {
    C* pc = new C;
    delete pc;

    return 0;
}