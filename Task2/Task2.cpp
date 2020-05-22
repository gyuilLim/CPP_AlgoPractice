#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int m, int n);
int gcm(int m, int n);

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    printf("%d\n", gcd(m,n));
    printf("%d\n", gcm(m,n));


    return 0;
}

int gcd(int m, int n){
    int r;
    while(1){
        r = m % n;
        if (r == 0) return n;
        else {
            m = n;
            n = r;
        }
    }
}

int gcm(int m, int n){
    return m*n/gcd(m,n);
}