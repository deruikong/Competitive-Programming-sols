#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull mod = 1e9;

vector<vector<ull>> binpow(vector<vector<ull>> n, vector<vector<ull>> m){
    vector<vector<ull>> a(2,vector<ull>(3));
    a[0][0] = (n[0][0]*m[0][0]+n[1][0]*m[0][1])%mod;
    a[1][0] = (n[0][0]*m[1][0]+n[1][0]*m[1][1])%mod;
    a[0][1] = (n[0][1]*m[0][0]+n[1][1]*m[0][1])%mod;
    a[1][1] = (n[0][1]*m[1][0]+n[1][1]*m[1][1])%mod;
    return a;
}

int main() {
    ull k, a, b;
    cin >> a >> b >> k;
    vector<vector<ull>> mat = {{1,1}, {1,0}}, res = mat;
    vector<ull> ori{b, a}, ans{0,0};
    if(k == 0){cout << a << endl;return 0;}
    if(k == 1){cout << b << endl;return 0;}
    k-=2;
    while (k > 0) {
        if (k & 1) res = binpow(res, mat);
        mat = binpow(mat, mat);
        k >>= 1;
    }
    ans[0] = (res[0][0]*ori[0]+res[0][1]*ori[1])%mod;
    cout << ans[0] << endl;
    return 0;
};