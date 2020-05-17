#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N, M, tot, d;
map<int, int> adj[10002];
vector<int> mst[10002];
set<int> stupid;

void primMST(){
    priority_queue<pii, vector<pii>, less<pii>> q;
    vector<int> key(N+1, -1), parent(N+1, -1);
    vector<bool> vis(N+1, 0);
    q.emplace(0, 1);
    key[1] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        vis[u] = true;
        for(auto pp: adj[u]){
            int v = pp.first;
            int w = pp.second;
            if(!vis[v] && w > key[v]){
                key[v] = w;
                q.emplace(key[v], v);
                parent[v] = u;
            }
        }
    }
    REP(i, 2, N){
        mst[parent[i]].push_back(i);
    }
}

void bfs(){
    int res = INF;
    list<pii> q;
    q.emplace_back(1, INF);
    while(!q.empty()){
        pii cur = q.front();q.pop_front();
        if(stupid.find(cur.first) != stupid.end()){
            res = min(res, cur.second);
        }
        for(int v: mst[cur.first]){
            //cout << cur.first << " " << v << adj[cur.first][v] << endl;
            q.emplace_back(v, min(cur.second, adj[cur.first][v]));
        }
    }
    printf("%d\n", res);
}

int main(){
    scanf("%d%d%d", &N, &M, &d);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d%d%d", &u,&v, &w);
        adj[u][v] = (adj[u].find(v)==adj[u].end())?w:max(adj[u][v], w);
        adj[v][u] = (adj[v].find(u)==adj[v].end())?w:max(adj[v][u], w);
    }
    primMST();
    REP(i, 1, d){
        int c;
        scanf("%d", &c);
        stupid.insert(c);
    }
    bfs();
    return 0;
}