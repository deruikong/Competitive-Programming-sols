//
// Created by RayKo on 2020-02-29.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> visit(2001, 0);
vector<int> adj[2001];

void dfs(int curr){
    visit[curr] = true;
    for(int ad: adj[curr])
    {
        if(!visit[ad])dfs(ad);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, bb, ba;
    cin >> n >> m >> a >> b;
    for(int i = 0; i< m; i++){
        cin >> ba >> bb;
        adj[ba].push_back(bb);
        adj[bb].push_back(ba);
    }
    dfs(a);
    if(visit[b])cout << "GO SHAHIR!";
    else cout << "NO SHAHIR!";
    return 0;
};
