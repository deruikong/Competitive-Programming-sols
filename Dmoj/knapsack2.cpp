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

const int V_MAX = 1e5;
ll dp[2][V_MAX + 2];

int main(){
	int N, W;
	scan(N);scan(W);
	memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 0;
	// cout << dp[N%2][V_MAX];
	REP(i, 1, N){
		int a, b;
		scan(a);scan(b);
		//cout << i%2 << endl;
		REP(j, 1, V_MAX){
			if(j < b){
				dp[i%2][j] = dp[(i-1)%2][j];
				//cout << j << ":" << ((dp[i%2][j]==INF)?-1:dp[i%2][j]) << "," << ((dp[(i-1)%2][j]==INF)?-1:dp[(i-1)%2][j]) <<"   ";
				continue;
			}
			ll tmp = dp[(i-1)%2][j-b];
			dp[i%2][j] = min(dp[(i-1)%2][j], tmp + a);
			// cout << j << ":" << ((dp[i%2][j]==INF)?-1:dp[i%2][j]) << "," << (dp[(i-1)%2][j] < (tmp + a)) <<"   ";
		}
		// cout << endl;
	}
	for(int i = V_MAX; i > 0; i--){
		if(dp[N%2][i] <= W){
			//cout << dp[N%2][i] << endl;
			cout << i << endl;
			break;
		}
	}
	return 0;
}