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
const int MM = 1e6 + 1, MQ = 5e5 + 1;

ll N, ans[MQ];
char word[MM];
int t, m, len, psa[MM];
vector<pll> queries[26];

int get_pos(ll ln){
	ll a, b;
	if(ln & 1) a = ln, b = (ln + 1) / 2;
	else a = ln / 2, b = ln + 1;
	a %= m, b %= m;
	return a*b % m;
}

int cnt(int p1, int p2){
	return psa[p2] - (p1==0 ? 0 : psa[p1 - 1]);
}

ll solve(ll ln){
	ll ans = 0, left = ln, p0, p1;
	int pos = get_pos(ln - 1);
	left -= m - pos;
	// printf("pos is %d\n", pos);
	// get cnt for prefix
	if(ln + pos <= m)
		return cnt(pos, pos + ln - 1);
	else
		ans += cnt(pos, m - 1);
	// get whole
	if(left >= m){
		ans += 1LL * cnt(0, m - 1) * (left/m);
	}
	// if left, get suffix
	if(left%m > 0)ans += cnt(0, left%m - 1);
	return ans;
}

int main(){
	// #ifdef ray
	// 	freopen("in", "r", stdin);
	// #endif
	scan(N);
	scanf("%s", word);
	m = strlen(word);
	scan(t);
	REP(i, 1, t){
		ll ln; char let;
		scanf("%lld %c", &ln, &let);
		queries[let - 'A'].emplace_back(ln, i);
		//solve(ln, let - 'A');
	}

	REP(i, 0, 25){
		memset(psa, 0, sizeof(psa));
		REP(j, 0, m - 1){
			if(word[j] - 'A' == i)psa[j] = 1;
			if(j > 0)psa[j] += psa[j - 1];
		}
		REP(j, 0, queries[i].size() - 1){
			ans[queries[i][j].second] = solve(queries[i][j].first);
		}
	}
	REP(i, 1, t){
		printf("%lld\n", ans[i]);
	}
	return 0;
}