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
        const int operator *(const Vector2D& v1) const;
        friend const Vector2D operator +(const Vector2D& v1, const Vector2D& v2);
        friend const Vector2D operator -(const Vector2D& v1, const Vector2D& v2);
        friend bool operator ==(const Vector2D& v1, const Vector2D& v2);
        friend const Vector2D operator *(int k, const Vector2D& v);
        friend ostream& operator << (ostream& outputStream, const Vector2D& v);
    private:
        int x, y;

};
const int Vector2D::operator *(const Vector2D& v1) const{
    int a, b;
    a = x * v1.x;
    b = y * v1.y;
    return a+b;
}
const Vector2D operator +(const Vector2D& v1, const Vector2D& v2){
    int x, y;
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    return Vector2D(x, y);
}

const Vector2D operator -(const Vector2D& v1, const Vector2D& v2){
    int x, y;
    x = v1.x - v2.x;
    y = v1.y - v2.y;
    return Vector2D(x, y);
}

bool operator ==(const Vector2D& v1, const Vector2D& v2){
    return ((v1.x == v2.x) && (v1.y == v2.y));
}

const Vector2D operator *(int k, const Vector2D& v){
    int x, y;
    x = k * v.x;
    y = k * v.y;
    return Vector2D(x,y);
}
ostream& operator << (ostream& outputStream, const Vector2D& v){
    outputStream << "(" << v.x << "," << v.y << ")";
    return outputStream;
}


int main() {
    Vector2D v0, v1(2,2), v2(3,3), v3;

    cout << v1 << endl;
    cout << v1 + v2 << endl;

    return 0;
}

Vector2D::Vector2D(int x1, int y1):x(x1),y(y1){}
Vector2D::Vector2D():x(0),y(0){}

void Vector2D::output(){
    cout << "(" << x << "," << y << ")" << endl;
}
