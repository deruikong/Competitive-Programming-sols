#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const ll MOD = 199999993, base = 52;
int n; string str;
ll hs[5010], ppow[5010];
ll q(int l,int r){
    return (((hs[r]-hs[l]+MOD)%MOD)*ppow[n-l-1])%MOD;
}

void solve(){
	unordered_set<ll> vis;
	cin >> str; n = str.size();
	memset(hs, 0, sizeof(hs));
	memset(ppow,0, sizeof(ppow));
	ppow[0]=1;
	for(int i=1; i<=n; i++){
	    ppow[i]=(ppow[i-1]*base) % MOD;
	}
	for(int i = 0; i < n; i++){
		hs[i + 1] = (hs[i] + (ll)str[i]*ppow[i]) % MOD;
		// cout << hs[i + 1] << endl;
	}
	for(int l = 0; l <= n - 1; l++)for(int r = l + 1; r <= n; r++){
		ll curr = q(l, r);
		// for(int i = l; i < r; i++)cout << str[i];
		// cout << l << " " << r << " " << curr << endl;
		vis.insert(curr);
	}
	cout << vis.size() + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N; cin >> N;
	while(N--){
		solve();
	}
	return 0;
}