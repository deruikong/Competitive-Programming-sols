#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn =  5e3 + 3, INF = 0x3f3f3f3f;
int n, m;
vector<pii> adj[mn];
vector<int> dist_min(mn, INF), dist_2(mn, INF);

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	priority_queue<pii> pq;
	dist_min[1] = 0;
	pq.emplace(0, 1);

	while(!pq.empty()){
		int w = -pq.top().first, u = pq.top().second;pq.pop();
		// cout << u << " " << w << " " << dist_2[u] << endl;
		if(w > dist_2[u])continue;
		for(auto pp : adj[u]){
			int v = pp.first, alt = dist_min[u] + pp.second, alt2 = dist_2[u] + pp.second;
			if(alt < dist_min[v]){
				dist_min[v] = dist_2[v];
				dist_min[v] = alt;
				pq.emplace(-alt, v);
			}
			else if(alt < dist_2[v] && alt != dist_min[v]){
				dist_2[v] = alt;
				pq.emplace(-alt, v);
			}
			else if(alt2 < dist_2[v] && alt2 != dist_2[v]){
				dist_2[v] = alt2;
				pq.emplace(-alt2, v);
			}
		}
	}
	if(dist_2[n] == INF)printf("-1\n");
	else printf("%d\n", dist_2[n]);
	return 0;
}