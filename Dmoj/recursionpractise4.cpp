//
// Created by RayKo on 2020-03-16.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;
string a;
void freverse(int idx){
    if(idx==a.length()-1){printf("%c", a[idx]);return;}
    freverse(idx+1);
    printf("%c", a[idx]);
}

int main() {
    getline(cin, a);
    freverse(0);
    return 0;
};
