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
ll res;

ll cpow(int x){return 1LL*x*x;}

void solve(vector<int> a, vector<int> b, vector<int> c){
	for(int m : b){
		auto r = lower_bound(c.begin(), c.end(), m);
		auto l = upper_bound(a.begin(), a.end(), m);
		if(r == c.end() || l == a.begin())continue;
		l--;res = min(res, cpow(*r - m) + cpow(m - *l) + cpow(*r - *l));
	}
}

int main(){
	int t;
	scan(t);
	while(t--)
	{
		res = LINF;
		int nr, ng, nb;
		scan(nr);scan(ng);scan(nb);
		vector<int> r(nr), g(ng), b(nb);
		REP(i, 0, nr-1)scan(r[i]);
		sort(r.begin(), r.end());
		REP(i, 0, ng-1)scan(g[i]);
		sort(g.begin(), g.end());
		REP(i, 0, nb-1)scan(b[i]);
		sort(b.begin(), b.end());
		solve(r, g, b);solve(r, b, g);
		solve(g, r, b);solve(g, b, r);
		solve(b, g, r);solve(b, r, g);
		printf("%lld\n", res);
	}
	return 0;
}