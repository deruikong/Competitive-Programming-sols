#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
string a, b, d;
map<char, char> m;

int main(){
    getline(cin, a);
    getline(cin, b);
    getline(cin, d);
    for(int i = 0; i < b.length(); i++){
        m[b[i]] = a[i];
    }
    for(int i = 0; i < d.size(); i++){
        if(m.find(d[i])==m.end())d[i] = '.';
        else d[i] = m[d[i]];
    }
    cout << d;
    return 0;
}