#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
vector<pii> adj[200001];
vector<int> ree, reee;

// int diameter(){
//     pii best = make_pair(0,0);
//     list<pii> q;
//     vector<bool> vis(N, false);
//     REP(i, 0, N-1)if(!adj[i].empty()){q.emplace_back(i, 0);vis[i] = true;break;}
//     while(!q.empty()){
//         pii c = q.front();
//         q.pop_front();
//         best = (c.second > best.second)?c:best;
//         for(pii x: adj[c.first]){
//             if(vis[x.first])continue;
//             vis[x.first] = true;
//             q.emplace_back(x, c.second+x.second);
//         }
//     }
//     q.emplace_back(best.first, 0);
//     fill(vis.begin(), vis.end(), false);
//     vis[best.first] = true;
//     best = make_pair(0,0);
//     while(!q.empty()){
//         pii c = q.front();
//         q.pop_front();
//         best = (c.second > best.second)?c:best;
//         c.second++;
//         for(int x: adj[c.first]){
//             if(vis[x])continue;
//             vis[x] = true;
//             q.emplace_back(x, c.second);
//         }
//     }
//     return best.second;
// }
// int main(){
//     int N, T, tot = 0;
//     scanf("%d", &N);
//     ree.resize(N+2);
//     reee.resize(N+2);
//     REP(i, 1, N-1){
//         int u, v, w;
//         scanf("%d%d%d", &u, &v, &w);
//         adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
//         tot += 2*w;
//     }
//     int f = 0, s = 0;
//     REP(i, 1, N){
//         int c = max(ree[i], reee[i]);
//         cout << c<< endl;
//         // if(c > f)s = f, f = c;
//         // else if(c > s)s = c;
//     }
//     printf("%d", s);
// }