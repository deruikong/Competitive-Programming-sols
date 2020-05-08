#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N;
vector<int> adj[10002];

void bfs(){
    vector<bool> vis(N+1, false);
    int choses = INT_MAX;
    vis[1] = true;
    list<pii> q;q.emplace_back(1,0);
    while(!q.empty()){
        pii c = q.front();q.pop_front();
        if(adj[c.first].empty())choses = min(choses, c.second);
        c.second++;
        for(int x: adj[c.first]){
            if(!vis[x])vis[x] = true, q.emplace_back(x, c.second);
        }
    }

    REP(i, 1, N){
        if(!vis[i]){printf("N\n%d", choses+1);return;}
    }
    printf("Y\n%d", choses+1);
}

int main(){
    scanf("%d", &N);
    REP(i, 1, N){
        int M;
        scanf("%d", &M);
        REP(j, 1, M){
            int a;
            scanf("%d", &a);
            adj[i].push_back(a);
        }
    }
    bfs();
    return 0;
}