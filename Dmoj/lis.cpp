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

// O(N^2) array

int main(){
	int N, len = 1;
	scan(N);
	vector<int> arr(N), dp(N, 0);
	REP(i, 0, N-1){
		scan(arr[i]);
	}
	dp[0] = arr[0];
	REP(i, 1, N-1){
		auto it = lower_bound(dp.begin(), dp.begin() + len, arr[i]);
		if (it == dp.begin() + len)
			dp[len++] = arr[i];
		else
			*it = arr[i];
	}
	printf("%d", len);
	return 0;
}