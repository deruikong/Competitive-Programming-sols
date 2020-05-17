#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e5 + 2;
vector<int> adj[mn];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}