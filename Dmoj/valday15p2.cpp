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

int dp[2][(int)1e3 + 1];

int main(){
	int C, M;
	scan(C);scan(M);
	REP(i, 1, C){
		int a, b;
		scan(a);scan(b);
		REP(j, 1, M){
			if(j < b){
				dp[i % 2][j] = dp[(i - 1) % 2][j];
			}
			else{
				dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - b] + a);
			}
		}
	}
	printf("%d", dp[C % 2][M]);
	return 0;
}