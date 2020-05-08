#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
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
const int MAXN = 2e5 + 1;
int N, K;

struct node{
	int p, t, cities = -INF;
	bool operator<(const node& other) const{
		return cities > other.cities;
	}
};

vector<int> adj[MAXN];
vector<node> forest(MAXN + 1);
vector<bool> vis(MAXN, false);

void dfs(int u, int prev){
	vis[u] = true;
	if(adj[u].empty())forest[u].t = 0;
	if(u != prev) forest[u].cities = forest[prev].cities + 1;
	for(int v : adj[u]){
		if(!vis[v]){
			forest[v].p = u;
			dfs(v, u);
			forest[u].t += forest[v].t + 1;
		}
	}
}

int main(){
	scan(N); scan(K);
	forest.resize(N + 2);
	REP(i, 1, N-1){
		int u, v;
		scan(u);scan(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	forest[1] = node{0, 0, 0};
	dfs(1, 1);
	REP(i, 1, N){
		forest[i].cities -= forest[i].t;
	}
	sort(forest.begin(), forest.end());
	// REP(i, 0, N - 1){
	// 	cout << i << " : " << forest[i].cities << endl;
	// }
	ll tot = 0;
	REP(i, 0, K-1){
		tot += forest[i].cities;
	}
	printf("%lld", tot);
	return 0;
}