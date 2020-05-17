//
// Created by RayKo on 2020-03-08.
//

#include <bits/stdc++.h>
#define INF 1e8
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    vector<pair<string, int>> q;
    //inputs
    cin >> a;
    cin >> b;
    for(int i = 0; i < b; i++){
        string c;
        int c1;
        cin >> c;
        cin >> c1;
        q.emplace_back(c, c1);
    }

    vector<int> best(b+1, INF);
    vector<int> group(b+1, -1);
    vector<vector<string>> fuckdp;
    best[0] = group[0] = 0;
    //best time
    for(int i = 0; i < b+1 ; i++){
        int cur = 0;
        for(int j = 1; j <= a && i+j-1 < b; j++)
        {
            cur = max(cur, q[i+j-1].second);
            if(best[i]+cur < best[i+j]){
                best[i+j] = best[i]+ cur;
                group[i+j] = j;
            }
        }
    }
    cout << "Total Time: " << best[b] << endl;
    //get the groups and reverse
    for(int i = b; i > 0; i--){
        vector<string> cur;
        for(int j = 0; j < group[i]; j++)cur.push_back(q[i-j-1].first);
        i -= group[i]-1;
        reverse(cur.begin(), cur.end());
        fuckdp.push_back(cur);
    }
    reverse(fuckdp.begin(), fuckdp.end());
    //print lines cuz what else to do
    for(auto& x: fuckdp){
        for(auto& y: x) cout << y << ' ';
        cout << endl;
    }
    return 0;
};
