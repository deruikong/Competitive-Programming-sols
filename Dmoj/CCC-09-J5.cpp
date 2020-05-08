#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

set<int> adj[52] = {{}, {6}, {6}, {4, 5, 6, 15}, {3, 5, 6}, {3, 4, 6}, {1, 2, 3, 4, 5, 7}, {6, 8}, {7, 9}, {8, 10, 12}, {9, 11}, {10, 12}, {9, 11, 13}, {12, 14, 15}, {13}, {3, 13}, {17, 18}, {16, 18}, {16, 17}};

int bfs(int idx){
    int ret = 0;
    vector<bool> vis(51, false);
    vis[idx] = true;
    list<int> q, q1;
    q.push_back(idx);
    while(!q.empty()){
        int c = q.front();q.pop_front();
        for(int x: adj[c]){
            if(!vis[x]){
                vis[x] = true;
                q1.push_back(x);
            }
        }
    }
    while(!q1.empty()){
        int c = q1.front();q1.pop_front();
        for(int x: adj[c]){
            if(!vis[x]){
                vis[x] = true;
                ret++;
            }
        }
    }
    return ret;
}

void dfs(int a, int b){
    vector<bool> vis(51, false);
    list<pii> q;q.emplace_back(a, 0);
    vis[a] = true;
    while(!q.empty()){
        pii c = q.front();q.pop_front();
        if(c.first == b){
            cout << c.second << endl;return;
        }
        c.second++;
        for(int x: adj[c.first]){
            if(!vis[x]){
                vis[x] = true;
                q.emplace_back(x, c.second);
            }
        }
    }
    cout << "Not connected" << endl;
}

int main(){
    string cmd;
    cin >> cmd;
    while(cmd != "q"){
        if(cmd == "i"){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].insert(b);
            adj[b].insert(a);
        }
        else if(cmd == "d"){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].erase(b);
            adj[b].erase(a);
        }
        else if(cmd == "n"){
            int a;
            scanf("%d", &a);
            printf("%d\n", adj[a].size());
        }
        else if(cmd == "f"){
            int a;
            scanf("%d", &a);
            printf("%d\n", bfs(a));
        }
        else if(cmd == "s"){
            int a, b;
            scanf("%d%d", &a, &b);
            dfs(a, b);
        }
        cin >> cmd;
    }
    return 0;
}