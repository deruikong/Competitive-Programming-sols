//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;



string fpow(int a){
    if(a== 0)return "";
    if(a== 1)return "2(0)";
    if(a== 2)return "2";
    int H = 15, L = 0;
    int mid;
    while (L < H){
        mid = ceil((L+H)/2.0);
        if(1<<mid > a)H = mid-1;
        else(L = mid);
    }
    string suffix = fpow(a-(1<<L));
    string prefix = (L==1?"2":("2(" + fpow(L) +")"));
    prefix += suffix.empty()?"":("+" + suffix);
    return prefix;
}

int main() {
    int N;
    scanf("%d", &N);
    cout << fpow(N);
    return 0;
};
