#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

vector<ll> ppow(32, 0);
map<ll, ll> cnt;
int32_t main(){
	ll ans = 0;
	ll n;
	scan(n);
	vector<ll> arr(n + 1);
	ppow[0] = 1;
	for(ll i = 1; i < 32; i++){
		ppow[i] = ppow[i - 1] * 2;
		// cout << ppow[i] << endl;
	}
	for(ll i = 0; i < n; i++){
		scan(arr[i]);
		cnt[arr[i]]++;
	}
	for(ll i = 0; i < n; i++){
		cnt[arr[i]]--;
		for(ll pow : ppow){
			// if(cnt.count(pow - arr[i])){
			// 	cout << arr[i] << " " << pow<< " " << cnt[pow - arr[i]] << endl;
			// }
			ans += cnt[pow - arr[i]];
		}
	}
	printf("%lld\n", ans);
	return 0;
}