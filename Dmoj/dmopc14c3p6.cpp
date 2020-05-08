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
const int MN = 2e3 + 1, MT = 1e5 + 1;
int N, T, dp[2][MT], p[3], c[3];

int main(){
	scan(N);scan(T);
	//memset(dp, 0, sizeof(dp));
	//REP(i, 0, 2)dp[0][i] = 0;
	REP(i, 1, N){
		bool cur = i%2, prev = (i-1)%2;
		REP(j, 0, 2){
			scan(p[j]);scan(c[j]);
		}
		REP(k, 1, T){
			REP(j, 0, 2){
				if(k - p[j] < 0){
					dp[cur][k] = max(dp[prev][k], dp[cur][k]);
				}
				else{
					dp[cur][k] = max(dp[cur][k], max(dp[prev][k], dp[prev][k-p[j]] + c[j]));
				}
				// cout << k << " : " << dp[cur][k] << endl;
			}
		}
		// cout << endl;
	}
	// REP(i, 1, T){
	// 	cout << dp[N%2][i] << " ";
	// }
	cout << dp[N%2][T] << endl;
	return 0;
}