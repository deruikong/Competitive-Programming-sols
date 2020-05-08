//
// Created by RayKo on 2020-02-29.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 0, n, tot = 0;
    string cur;
    cin >> n;
    map<string, int> c;
    for(int i = 0; i< n; i++)
    {
        cin >> cur;
        if(c[cur] > tot-c[cur])a++;
        c[cur]++;
        tot++;
    }
    cout << a;
    return 0;
};
