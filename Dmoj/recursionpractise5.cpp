//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int ipow(int base, int exp) {
    int result = 1;
    for (;;) {
        if (exp & 1)result *= base;
        exp >>= 1;
        if (!exp)break;
        base *= base;
    }
    return result;
}

int superdigit(int a){
    if(a%10 == a)return a;
    int b = 0;
    do{
        b+=a%10;
        a/=10;
    }
    while(a > 0);
    superdigit(b);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", superdigit(N));
    return 0;
};
