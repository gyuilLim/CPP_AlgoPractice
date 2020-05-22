#include <iostream>
using namespace std;

class Vector2D{
    public:
        Vector2D();
        Vector2D(int x1, int y1);
        void output();
        int getX() const{
            return x;
        }
        int getY() const{
            return y;
        }
    private:
        int x, y;

};
const Vector2D operator +(const Vector2D& v1, const Vector2D& v2){
    int x, y;
    x = v1.getX() + v2.getX();
    y = v1.getY() + v2.getY();
    return Vector2D(x, y);
}

const Vector2D operator -(const Vector2D& v1, const Vector2D& v2){
    int x, y;
    x = v1.getX() - v2.getX();
    y = v1.getY() - v2.getY();
    return Vector2D(x, y);
}

bool operator ==(const Vector2D& v1, const Vector2D& v2){
    return ((v1.getX() == v2.getX()) && (v1.getY() == v2.getY()));
}


int main() {
    Vector2D v0, v1(2,2), v2(3,3), v3;

    v3 = v1 + v2;
    v3.output();

    v3 = v2 - v2;
    v3.output();
    if (v3 == v0){
        cout << "Operator - works!";
    }

    return 0;
}

Vector2D::Vector2D(int x1, int y1):x(x1),y(y1){}
Vector2D::Vector2D():x(0),y(0){}

void Vector2D::output(){
    cout << "(" << x << "," << y << ")" << endl;
}