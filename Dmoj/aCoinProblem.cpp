#include <bits/stdc++.h>
using namespace std;

bool myfunction (vector<int> i,vector<int> j) { return (i[1]<j[1]);}

int main() {
    int n, v, m = 0, mc = 0, cur = 0;
    ;
    cin >> n >> v;
    vector<int> coin(n), ans(v);
    vector<vector<int>> store(v, vector<int> (3));
    for(int i = 0; i < n; i++)cin >>coin[i];
    for(int i = 0; i < v; i++)
    {
        cin >> store[i][0] >> store[i][1];
        m = max(m, store[i][0]);
        store[i][2] = i;
    }
    vector<int> dp(m+1, m+1);
    sort(store.begin(), store.end(), myfunction);
    dp[0] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            if(j-coin[i]>=0)dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
        while(cur < v && store[cur][1] <= i+1){
            cout << dp[store[cur][0]];
            ans[store[cur][2]] = min(ans[store[cur][2]], dp[store[cur][0]]);
            cur++;
        }

    }
    for(int i = 0; i < v; i++)
    {
        if(ans[i] < m+1)cout << ans[i] << endl;
        else cout << -1 << endl;
    }
    return 0;
};