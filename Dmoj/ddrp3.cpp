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
vector<int> adj[1000006];
int bfs(int u ,int v){
    vector<bool> vis(N+2, false);
    list<pii> q;q.emplace_back(u, 0);
    vis[u] = true;
    while(!q.empty()){
        pii cur = q.front();
        q.pop_front();
        if(cur.first == v){
            return cur.second;
        }
        for(int x: adj[cur.first]){
            if(!vis[x])vis[x] = true, q.emplace_back(x, cur.second+1);
        }
    }
    return 0;
}

int main(){
    scanf("%d%d", &N, &M);
    stringstream o;
    REP(i, 0, M-1){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", M-bfs(u, v));
    return 0;
}
