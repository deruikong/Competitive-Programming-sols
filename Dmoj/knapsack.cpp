#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
pair<ll, int> dp[5002];

int main(){
	ll ans = -2e9;
	int N, M;
	scan(N);scan(M);
	for(int i = 0; i <= 5000; i++)dp[i] = make_pair(-2e9, 0);
	dp[0] = make_pair(0, 0);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scan(a);scan(b);scan(c);
		for(int j = 0; j <= 5000; j++){
			dp[j].second = 0;
		}
		for(int j = 0; j <= 5000; j++){
			if(j < b)continue;
			pair<ll, int> alt = make_pair(dp[j - b].first + c, dp[j - b].second - 1);
			if(alt.second >= -c && alt.first >= 0){
				// cout << alt.second << endl;
				dp[j] = max(dp[j], alt);
				// cout << dp[j - b].first << " " << dp[j].first << endl;
			}
		}

	}
	for(int i = 1; i <= 5000; i++){
		dp[i].first = max(dp[i].first, dp[i - 1].first);
	}

	for(int i = 0; i < M; i++){
		int a, b;
		scan(a);scan(b); 
		ans = max(ans, dp[a].first - b);
	}

	cout << ans << endl;
	return 0;
}