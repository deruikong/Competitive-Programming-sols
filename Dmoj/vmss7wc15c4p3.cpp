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

struct ed{
	int v, w;
	bool operator<(const ed& b)const{
		return w > b.w;
	}
};
int N, M, dist[2][100001];
vector<ed> adj[100001];

void dijk(int idx){
	priority_queue<ed> q;
	q.push(ed{idx?(N-1):0, 0});
	while(!q.empty()){
		ed c = q.top();q.pop();
		// cout << c.v << " : " << c.w << endl;
		if(c.w > dist[idx][c.v])continue;
		for(ed x : adj[c.v]){
			//cout << x.v << " : " << x.w << endl;
			int alt = x.w + c.w;
			if(alt < dist[idx][x.v]){
				dist[idx][x.v] = alt;
				q.push(ed{x.v, alt});
			}
		}
	}
	//cout << endl;
}

int main(){
	scan(N);scan(M);
	memset(dist, INF, sizeof(dist));
	REP(i, 1, M){
		int u, v, w;
		scan(u);scan(v);scan(w);
		adj[u].push_back(ed{v, w});
		adj[v].push_back(ed{u, w});
	}
	dist[0][0] = 0, dist[1][N-1] = 0;
	dijk(0), dijk(1);
	int best = 0;
	REP(i, 0, N-1){
		//cout << dist[0][i] << " " << dist[1][i] << endl;
		best = max(dist[1][i] + dist[0][i], best);
	}
	printf("%d", best);
	return 0;
}