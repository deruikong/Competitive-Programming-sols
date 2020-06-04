#include "bits/stdc++.h"
#define int long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
char _;
const int mn = 3e5 + 2;
int n, ans,
	w[mn], pre[mn], aft[mn];
bool vis[mn];
vector<pii> adj[mn];

void dfs(int u, int p, int ww){
	pre[u] = max(0LL, aft[p] - ww);
	for(auto pp : adj[u]){
		int v = pp.first, alt = pp.second;
		if(v != p){
			dfs(v, u, alt);
			aft[u] = max(aft[u], w[u] + aft[v] - alt);
		}
	}
	ans = max(ans, aft[u] + pre[u]);
}

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
		aft[i] = w[i];
	}
	for(int i = 1; i <= n - 1; i++){
		int u, v, c; cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	dfs(1, 0, 0);
	// for(int i = 1; i <= n; i++){
	// 	cout << dp[i] << endl;
	// }
	cout << ans << endl;
	return 0;
}