#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N, M;
set<int> pho;
set<int> adj[100001];
vector<bool> vis(100000, false);

void bfs(int i){
    if(vis[i])return;
    vis[i] = true;
    list<int> q;
    q.push_back(i);
    while(!q.empty()){
        int cur = q.front();q.pop_front();
        if(pho.find(cur) != pho.end())continue;
        for(int x: adj[cur]){
            if(vis[x])continue;
            adj[x].erase(cur);
            //adj[cur].erase(x);
            if(adj[x].size()<=1){
                q.push_back(x);
                vis[x] = true;
            }
        }
        adj[cur].clear();
    }
}

int diameter(){
    pii best = make_pair(0,0);
    list<pii> q;
    vector<bool> vis(N, false);
    REP(i, 0, N-1)if(!adj[i].empty()){q.emplace_back(i, 0);vis[i] = true;break;}
    while(!q.empty()){
        pii c = q.front();
        q.pop_front();
        best = (c.second > best.second)?c:best;
        c.second++;
        for(int x: adj[c.first]){
            if(vis[x])continue;
            vis[x] = true;
            q.emplace_back(x, c.second);
        }
    }
    q.emplace_back(best.first, 0);
    fill(vis.begin(), vis.end(), false);
    vis[best.first] = true;
    best = make_pair(0,0);
    while(!q.empty()){
        pii c = q.front();
        q.pop_front();
        best = (c.second > best.second)?c:best;
        c.second++;
        for(int x: adj[c.first]){
            if(vis[x])continue;
            vis[x] = true;
            q.emplace_back(x, c.second);
        }
    }
    return best.second;
}

int main(){
    scanf("%d%d", &N, &M);
    REP(i, 0, M-1){
        int cur;
        scanf("%d", &cur);
        pho.insert(cur);
    }
    REP(i, 1, N-1){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    REP(i, 0, N-1){
        if(adj[i].size() == 1)bfs(i);
    }
    int tot = 0;
    REP(i, 0, N-1) if(!adj[i].empty())tot++;
    cout << 2*(tot-1)-diameter();
    return 0;
}