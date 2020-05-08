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
const int MAXN = 1e5 + 2;
int N, h[MAXN], dp[MAXN];

int main(){
	scan(N);
	REP(i, 1, N) scan(h[i]);
	memset(dp, INF, sizeof(dp));
	dp[1] = 0;
	REP(i, 1, N - 1){
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i]-h[i + 1]));
		if(i == N-1)break;
		dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i]-h[i + 2]));
	}
	cout << dp[N] << endl;
	return 0;
}