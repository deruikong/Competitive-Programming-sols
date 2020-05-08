//
// Created by RayKo on 2020-03-12.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int cut(int w, int h){
    if(w == h) return 0;
    if(w > h) return cut(w-h,h)+1;
    else if(h > w)return cut(w, h-w)+1;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << cut(a, b);
    return 0;
};
