#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N,M;
vector<int> adj[10002];
bool vis[10002];

bool dfs(int i, set<int> t){
    bool ret = false;
    vis[i] = true;
    t.insert(i);
    for(int x: adj[i]){
        if(t.find(x) != t.end())return true;
        else if(!vis[x])ret = max(ret, dfs(x, t));
    }
    return ret;
}

int main(){
    scanf("%d%d", &N, &M);
    memset(vis, false, sizeof(vis));
    for(int i = 0; i< M; i++){
        int a,b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    for(int i = 1; i<=N; i++){
        if(!vis[i]){
            if(dfs(i, {})){printf("N");return 0;}
        }
    }
    printf("Y");
    return 0;
}