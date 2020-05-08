#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int MN  = 2e5 + 5;
ll dp[MN];
map<ll, int> mp;

int main(){
	int n, m = 0;
	scan(n);
	ll ans = 0;
	dp[0] = 0, mp[0] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &dp[i]);
		dp[i] += dp[i - 1];
	}
	for(int i = 1; i <= n; i++){
		m = max(m, mp[dp[i]]);
		//cout << m << " ";
		ans += i - m;
		mp[dp[i]] = i + 1;
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}