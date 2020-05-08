#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
char _;

struct ed{
	int u, w, h;
	bool operator<(const ed& b) const{
		return w > b.w;
	}
};

int K, N, M, A, B, dist[2001][201];
vector<ed> adj[2001];


void dijk(){
	vector<bool> vis(N + 1, false);
	priority_queue<pii> q;
	dist[A][0] = 0;
	q.emplace(0, A);
	vis[A] = true;
	while(!q.empty()){
		int u = q.top().second; q.pop();
		vis[u] = false;
		for(ed i : adj[u]){
			for(int j = 0; j + i.h < K; j++){
				int alt = dist[u][j] + i.w;
				if(alt < dist[i.u][j + i.h]){
					dist[i.u][j + i.h] = alt;
					if(!vis[i.u])vis[i.u] = true, q.emplace(-alt, i.u);
				}
			}
		}
	}
}

int main(){
    freopen("D:/Ray/C/Competitive/USACO/usopen20/socdist.in", "r", stdin);
	scan(K);scan(N);scan(M);
	memset(dist, INF, sizeof(dist));
	REP(i, 1, M){
		int a, b, t, h;
		scan(a);scan(b);scan(t);scan(h);
		adj[a].push_back(ed{b, t, h});
		adj[b].push_back(ed{a, t, h});
	}
	scan(A);scan(B);
	dijk();
	int b = INF;
	REP(i, 0, K-1)b = min(b, dist[B][i]);
	if(b == INF)cout << -1 << endl;
	else cout << b << endl;
	return 0;
}