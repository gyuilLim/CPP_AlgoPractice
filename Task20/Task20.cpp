#include <iostream>
using namespace std;

class PFArrayI{
    public:
        PFArrayI();
        PFArrayI(int capacityValue);
        PFArrayI(const PFArrayI& pfaObject);
        void addElement(int element);
        bool full() const {return (capacity == used);}
        int getCapacity() const {return capacity;}
        int getNumberUsed() const {return used;}
        void emptyArray() {used = 0;}
        int& operator[] (int index);
        PFArrayI& operator= (const PFArrayI& rightSide);
        ~PFArrayI();
    private:
        int *a;
        int capacity;
        int used;
};  

PFArrayI::PFArrayI() : capacity(50), used(0){
    a = new int[capacity];
}
PFArrayI::PFArrayI(int size) : capacity(size), used(0){
    a = new int[capacity];
}
PFArrayI::PFArrayI(const PFArrayI& pfaObject)
:capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new int[capacity];
    for (int i = 0; i < used; i++){
        a[i] = pfaObject.a[i];
    }
}
void PFArrayI::addElement(int element){
    if (used >= capacity){
        cout << "Attempt to exeed capacity in PFArrayI.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}
PFArrayI& PFArrayI::operator=(const PFArrayI& rightSide){
    if (capacity != rightSide.capacity){
        delete [] a;
        a = new int[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++){
        a[i] = rightSide.a[i];
    }
    return *this;
}
int& PFArrayI::operator[](int index){
    return a[index];
}
PFArrayI::~PFArrayI(){
    delete [] a;
}

int main() {
    int cap;

    cout << "Enter capacity of this super array: ";

    cin >> cap;

    PFArrayI temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";

    cout << "Place a negative number at the end.\n";

    int next;

    cin >> next;

    while ((next >= 0) && (!temp.full( )))

    {

        temp.addElement(next);

        cin >> next;

    }

    cout << "You entered the following "

    << temp.getNumberUsed( ) << " numbers:\n";

    int index;

    int count = temp.getNumberUsed( );

    for (index = 0; index < count; index++)

        cout << temp[index] << " ";

    cout << endl;
    return 0;
}