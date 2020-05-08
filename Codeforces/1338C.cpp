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
const int MAXN = 1e5 + 1;

struct node{
	bool o = 1;
	int p;
};

int N;
vector<int> adj[MAXN];
vector<node> tree(MAXN);
vector<bool> vis(MAXN, false);
vector<int> leaves;
set<int> m;
void dfs(int u, int prev){
	vis[u] = true;
	for(int v : adj[u]){
		if(!vis[v]){
			tree[v].o ^= tree[u].o;
			// cout << tree[v].o << " " << v << endl;
			tree[v].p = u;
			dfs(v, u);
		}
	}
}

int main(){
	scan(N);
	REP(i, 1, N-1){
		int u, v;
		scan(u);scan(v);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	REP(i, 1, N){
		if(adj[i].size() == 1){
			if(!vis[i]){
				tree[i].o = 1;
				tree[i].p = i;
				dfs(i, i);
			}
			else{
				m.insert(tree[i].p);
			}
			leaves.push_back(i);

		}
	}
	int par = -1;
	bool s = true;
	for(int u : leaves){
		// cout << u << " " << tree[u].p << endl;
		if(par == -1)par = tree[u].o;
		else if(par != tree[u].o){
			s = false;
			break;
		}
	}
	if(s)printf("1 ");
	else printf("3 ");
	for(int u : adj[leaves[0]]){
		if(adj[u].size() > 1)m.insert(u);
	}
	//printf("%d %d %d", (N-1), leaves.size(), m.size());
	printf("%d", (N-1) - leaves.size() + m.size());
	return 0;
}