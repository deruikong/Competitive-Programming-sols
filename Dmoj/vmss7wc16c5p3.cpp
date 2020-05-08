#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

vector<int> adj[10002];
int N;

int diameter(){
    pii best = make_pair(0,0);
    list<pii> q;
    vector<bool> vis(N+1, false);
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
    scanf("%d", &N);
    REP(i, 1, N){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printf("%d", diameter());
    return 0;
}