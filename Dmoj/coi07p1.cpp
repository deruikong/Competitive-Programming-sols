//
// Created by RayKo on 2020-03-08.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

//coci15c4p4
//coci13c1p5

vector<double> f;
double d;
int a;

bool check(double t){
    double pre = f[0]+t;
    for(int i = 1; i < a; i++){
        if(pre+d < f[i]-t)return false;
        pre = min(pre+d, f[i]+t);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //input
    cin >> d;
    cin >> a;
    for(int i = 0; i<a; i++){
        double cur;
        cin >> cur;
        f.push_back(cur);
    }
    //algo
    //do the thing
    double hi = 1e9, lo = 0;
    for(int i = 0; i < 100; i++){
        double mid = (hi+lo)/2;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    printf("%.4f\n",lo);
    return 0;
};
