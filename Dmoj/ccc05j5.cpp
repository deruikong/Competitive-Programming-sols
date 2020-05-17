#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

bool monkey(string c);

bool aword(string s){
    if(s == "A") return true;
    else if(s.size() >= 3 && s[0] == 'B' && monkey(s.substr(1, s.size()-2)) && s[s.size()-1] == 'S')return true;
    return false;
}

bool monkey(string c){
    bool ret = false;
    if(aword(c))return true;
    REP(i, 1, c.size()-1){
        ret = max(ret, (c[i]=='N' && aword(c.substr(0, i)) && monkey(c.substr(i+1, c.size()-i-1))));
    }
    return ret;
}

int main(){
    string m;
    cin >> m;
    while(m != "X"){
        if(monkey(m))cout << "YES" << '\n';
        else cout << "NO" << '\n';
        cin >> m;
    }
    return 0;
}