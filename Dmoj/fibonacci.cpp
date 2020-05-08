#include <bits/stdc++.h>
using namespace std;
vector<vector<unsigned long long>> binpow(vector<vector<unsigned long long>> n, vector<vector<unsigned long long>> m){
    vector<vector<unsigned long long>> a(2,vector<unsigned long long>(3));
    a[0][0] = (n[0][0]*m[0][0]+n[1][0]*m[0][1]);
    a[1][0] = (n[0][0]*m[1][0]+n[1][0]*m[1][1]);
    a[0][1] = (n[0][1]*m[0][0]+n[1][1]*m[0][1]);
    a[1][1] = (n[0][1]*m[1][0]+n[1][1]*m[1][1]);
    return a;
}

int main() {
    while(true){
        unsigned long long k;
        cin >> k;
        if(k == 0)break;
        vector<vector<unsigned long long>> mat = {{1,1},{1,0}}, res = mat;
        if(k > 2) {
            k = k-2;
            while (k > 0) {
                if (k & 1) res = binpow(res, mat);
                mat = binpow(mat, mat);
                k >>= 1;
            }
        }
        cout<< res[0][0] << endl;
    }
    return 0;
};