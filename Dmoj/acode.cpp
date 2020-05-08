#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;


int main(){
    string a;
    cin >> a;
    while(a != "0"){
        vector<ull> dp(a.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < a.size(); i++){
            int s = stoi(a.substr(i-1, 2));
            if(s == 0 || (s > 26 && s%10 == 0))break;
            if(s%10 != 0)dp[i] = dp[i-1];
            if(s < 10)continue;
            if(s <= 26)dp[i]+=(i>1)?dp[i-2]:1;
        }
        cout << dp[a.size()-1] << endl;
        cin >> a;
    }
    return 0;
}