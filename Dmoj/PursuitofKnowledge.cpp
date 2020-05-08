//
// Created by RayKo on 2020-03-04.
//

#include <bits/stdc++.h>
#define maxn 1005
#define ll long long int
using namespace std;

vector<vector<int>> adj(maxn);
map<pair<int,int>, int> ans;
vector<pair<int,int>> queries;
void bfs(int a){

    pair<int,int> r1 = make_pair(a, 0);
    list<pair<int,int>> q;
    vector<bool> vis(maxn, false);
    vis[r1.first] = true;
    q.push_back(r1);

    while(!q.empty()){
        r1 = q.front();
        q.pop_front();
        for(int r: adj[r1.first]){
            if(!vis[r]) {
                vis[r] = true;
                if(ans.find(make_pair(a+1, r+1)) != ans.end()){
                    ans[make_pair(a+1, r+1)] = min(ans[make_pair(a+1, r+1)], r1.second+1);
                }
                q.emplace_back(r, r1.second + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    cout << endl;

    int q;
    cin >> q;
    for(int i = 0; i<q; i++){
        pair<int, int> query;
        cin >> query.first >> query.second;
        if(query.first == query.second) cout << 0 << '\n';
        else{
            queries.push_back(query);
            ans[query] = 1e9;
        }
    }

    for(int i = 0; i < n; i++)bfs(i);

    for(auto& x: queries){
        if(ans[x] != 1e9)cout << ans[x]*t << '\n';
        else cout << "Not enough hallways!" << '\n';
    }
    return 0;
};
