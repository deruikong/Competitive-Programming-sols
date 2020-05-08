#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

set<int> adj[5];

bool bfs(){
    vector<bool> vis(4, false);
    list<int> q;
    q.push_back(0);
    vis[0] = true;
    while(!q.empty()){
        int c = q.front();q.pop_front();
        //cout << c<<endl;
        for(int i: adj[c]){
            if(vis[i])return false;
            else vis[i] = true, q.push_back(i);
            adj[i].erase(c);
        }
    }
    for(bool i:vis)if(!i)return false;
    return true;
}

int main(){
    REP(i, 0, 3){
        REP(j, 0, 3){
            int cur;
            scanf("%d", &cur);
            if(cur)adj[i].insert(j), adj[j].insert(i);
        }
    }
    if(bfs())printf("Yes");
    else printf("No");
    return 0;
}