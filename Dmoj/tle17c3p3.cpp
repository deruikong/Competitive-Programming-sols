#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N, M, q[300001];
ll dp[300001];
vector<int> child[300001];

ll dfs(int idx){
	if(dp[idx] != -1)return dp[idx];
	dp[idx] = q[idx];
	ll MIN = LLONG_MAX;
	for(int i : child[idx]){
		ll cur = dfs(i);
		if(cur == 0){
			MIN = 0;
			break;
		}
		MIN = min(MIN, cur);
	}
	if(MIN == LLONG_MAX)MIN = 0;
	dp[idx] += MIN;
	return dp[idx];
}

int main(){
	scanf("%d%d", &N, &M);
	memset(dp, -1, sizeof(dp));
	REP(i, 1, M){
		int par, t;
		scanf("%d%d", &par, &t);
		REP(i, 1, t){
			int c;
			scanf("%d", &c);
			child[par].push_back(c);
		}
	}
	REP(i, 1, N){
		int cur;
		scanf("%d", &cur);
		q[i] = cur;
	}
	ll ans = dfs(1);
	printf("%lld", ans);
	return 0;
}