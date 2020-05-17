#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const ll MOD = 1e9 + 7;
ll mod(ll x){return (MOD + (x % MOD)) % MOD;}
ll madd(ll a, ll b) {return mod(a + b); }
ll msub(ll a, ll b) {return mod(a - b); }
ll mmul(ll a, ll b) {return mod(mod(a) * mod(b));}

void apply(pair<ll, ll> fun, pair<ll, ll>& target){
	target.second = madd(target.second, mmul(fun.second, target.first));
	target.first = mmul(target.first, fun.first);
}

int main(){
	ll A, B, n, x;
	cin >> A >> B >> n >> x;
	pair<ll, ll> fun = {A, B}, res = {1, 0};
	while(n > 0){
		if(n & 1){
			apply(fun, res);
		}
		apply(fun, fun);
		n >>= 1;
	}
	cout << madd(mmul(res.first, x), res.second) << endl;
	return 0;
}