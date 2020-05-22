#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int answer;

    int *list = new int[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    sort(list, list+n);

    if (n == 1){
        answer = list[0] * list[0];
    }
    else{
        answer = list[0] * list[n-1];
    }

    printf("%d\n", answer);

    return 0;
}