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
const int MN = 1.5e3 + 2;
int N, M, K;
bitset<MN> adj[MN];

void go(){
	REP(i, 1, N){
		bitset<MN> tot, cur;
		tot[i] = 1;
		REP(k, 1, K){
			cur = tot;
			REP(j, 1, N){
				if(cur[j]){
					tot |= adj[j];
				}
			}
		}
		printf("%d\n", tot.count());
	}
}

int main(){
	memset(adj, INF, sizeof(adj));
	scan(N);scan(M);scan(K);
	REP(i, 1, N){
		adj[i].reset();
	}
	REP(i, 1, M){
		int u, v;
		scan(u);scan(v);
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	// REP(i, 1, N){
	// 	cout << adj[i].count() << endl;
	// }
	go();
	return 0;
}