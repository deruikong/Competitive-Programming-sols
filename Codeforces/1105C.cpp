#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const ll mn = 2e5, MOD = 1e9 + 7;
ll dp[mn + 2][3];
/*
states:
0 0
1 2
2 1

0 2
1 1
2 0


0 1
1 0
2 2
*/
ll fceil(ll x, ll y){return x/y + (x % y != 0);}

int main(){
	ll n, l, r, mod[3];
	cin >> n >> l >> r;
	for(int i = 0; i < 3; i++){
		mod[i] = (r - i)/3 - fceil(max(0LL, l - i), 3) + 1;
		if(r - i < 0)mod[i] = 0;
		dp[1][i] = mod[i];
		// cout << i << " " << (r - i)/3 << " " << mod[i] << endl;
	}
	// cout << endl;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				dp[i][j] += (mod[k] * dp[i - 1][(j + 3 - k) % 3]) % MOD;
			}
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}
	cout << dp[n][0] % MOD << endl;
	return 0;
}