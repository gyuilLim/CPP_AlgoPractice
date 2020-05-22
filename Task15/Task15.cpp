#include <iostream>
using namespace std;

class HotDogStand{
    public:
        HotDogStand(string name);
        string getName();
        void justSold(int sold);
        int getNumSold();
        static int getTotalNumSold();

    private:
        string shop_name;
        int solded = 0;
        static int allSolded;
        
};

int HotDogStand::allSolded = 0;

int main() {
    HotDogStand h1("SSU-1"), h2("SSU-2"), h3("CAU-1");
    h1.justSold(20);
    h2.justSold(50);
    h3.justSold(1);

    cout << h1.getName() << " has sold " << h1.getNumSold() << " hotdogs." << endl;

    cout << h2.getName() << " has sold " << h2.getNumSold() << " hotdogs." << endl;

    cout << h3.getName() << " has sold " << h3.getNumSold() << " hotdogs." << endl;

 

    cout << "Total sales are: " << HotDogStand::getTotalNumSold() << endl;


    return 0;
}

HotDogStand::HotDogStand(string name):shop_name(name){}

string HotDogStand::getName(){
    return shop_name;
}

void HotDogStand::justSold(int sold){
    solded += sold;
    allSolded += sold;
}

int HotDogStand::getNumSold(){
    return solded;
}

int HotDogStand::getTotalNumSold(){
    return allSolded;
}