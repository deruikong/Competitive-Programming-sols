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
const int MN = 1e3 + 1;
int N, dp[MN];

int main(){
	scan(N);
	memset(dp, -INF, sizeof(dp));dp[0] = 0;
	REP(i, 1, N){
		scan(dp[i]);
	}
	// dp[1] = val[1];
	REP(i, 1, N){
		REP(j, i, N){
			dp[j] = max(dp[j], dp[i] + dp[j - i]);
		}
	}
	cout << dp[N] << endl;
	return 0;
}