//
// Created by RayKo on 2020-03-18.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, res;
    getline(cin, a);
    for(char x:a){
        if(x-'a' < 0 && x!=32 && !res.empty())res.pop_back(),res.push_back('.'),res.push_back(' ');
        res.push_back(x);
    }
    res.push_back('.');
    cout << res << endl;
    return 0;
};
