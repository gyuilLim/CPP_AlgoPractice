#include <iostream>
using namespace std;

class NComplex{
    public:
        NComplex();
        NComplex(double r, double c);
        friend const NComplex operator +(const NComplex& n1, const NComplex& n2);
        friend const NComplex operator +(const NComplex& n, double d);
        friend const NComplex operator +(double d, const NComplex& n);
        friend const NComplex operator *(const NComplex& n1, const NComplex& n2);
        friend const NComplex operator -(const NComplex& n, double d);
        friend const NComplex operator -(double d, const NComplex& n);
        friend const NComplex operator *(double d, const NComplex& n);
        friend const NComplex operator *(const NComplex& n, double d);
        friend const NComplex operator /(const NComplex& n1, const NComplex& n2);
        friend const NComplex operator /(const NComplex& n, double d);
        friend const NComplex operator /(double d, const NComplex& n);
        friend ostream& operator << (ostream& outputStream, const NComplex& n);
    private:
        double real;
        double complex;
};

const NComplex operator +(const NComplex& n1, const NComplex& n2){
    double real_part, complex_part;
    real_part = n1.real + n2.real;
    complex_part = n1.complex + n2.complex;
    return NComplex(real_part, complex_part);
}
const NComplex operator +(const NComplex& n, double d){
    return NComplex(n.real+d, n.complex);
}
const NComplex operator +(double d, const NComplex& n){
    return NComplex(n.real+d, n.complex);
}

const NComplex operator *(const NComplex& n1, const NComplex& n2){
    double real_part, complex_part;
    double temp;
    real_part = n1.real*n2.real;
    temp = n1.complex * n2.complex;
    if (temp > 0){
        real_part = real_part - temp;
    }
    else if (temp < 0){
        real_part = real_part + temp;
    }
    complex_part = n1.real * n2.complex + n1.complex * n2.real;
    return NComplex(real_part, complex_part);
}

const NComplex operator -(const NComplex& n, double d){
    double real_part = n.real - d;
    return NComplex(real_part, n.complex);
}
const NComplex operator -(double d, const NComplex& n){
    double real_part = n.real - d;
    return NComplex(real_part, n.complex);
}

const NComplex operator *(double d, const NComplex& n){
    return NComplex(n.real*d, n.complex*d);
}

const NComplex operator *(const NComplex& n, double d){
    return NComplex(n.real*d, n.complex*d);
}

const NComplex operator /(const NComplex &n1, const NComplex &n2){
    if(n2.real == 0 || n2.complex == 0){
        cout << "Error: divide by zero";
        exit(0);
    }
    NComplex n2_c(n2.real, -n2.complex);
    double d = n2.real * n2.real + n2.complex * n2.complex;
    NComplex temp = n1 * n2_c;
    return NComplex(temp.real/d, temp.complex/d);
}
const NComplex operator /(const NComplex &n, double d){
    if(d == 0){
        cout << "Error: devide by zero";
        exit(0);
    }
    return NComplex(n.real/d, n.complex/d);
}


ostream& operator << (ostream& outputStream, const NComplex& n){
    outputStream << n.real << " + " << n.complex << "i";
    return outputStream;
}

int main() {
    NComplex n1 (5.1, 2.2), n2(2.0, 2.0), n3;
    double d1 = 3.0;

    cout << "n1 + n2 : " << n1+n2 << endl;
    cout << "n1 * n2 : " << n1*n2 << endl;
    cout << "n1 - d1 : " << n1 - d1 << endl;
    cout << "d1 * n2 : " << d1 * n2 << endl;
    cout << "n1 / n3 : " << n1/n3 << endl;

    return 0;
}

NComplex::NComplex():real(0), complex(0) {}
NComplex::NComplex(double r, double c):real(r), complex(c) {}