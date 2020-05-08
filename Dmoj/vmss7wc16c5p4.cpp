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
const int MN = 1e5 + 1;
int N, X, Y, Z, dp[MN], p[3];
int main(){
	scan(N);scan(p[0]);scan(p[1]);scan(p[2]);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	REP(i, 1, N){
		for(int j : p){
			if(i - j < 0 || dp[i-j] == -1)continue;
			dp[i] = max(dp[i], dp[i-j] + 1);
		}
	}
	cout << dp[N] << endl;
	return 0;
}