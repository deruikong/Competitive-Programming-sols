#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

ll fpow(ll a, ll exp){
	ll res = 1;
	while(exp > 0){
		if(exp & 1) res *= a;
		a *= a;
		exp >>= 1;
	}
	return res;
}

string to_tenary(ll n){
	string ret;
	int idx = 0;
	while(n > 0){
		ret += '0' + (n % 3);
		n /= 3;
	}
	// reverse(ret.begin(), ret.end());
	// cout << ret << endl;
	return ret;
}

void solve(){
	ll n, res = 0, idx0 = 0, idx2 = -1;
	scan(n);
	string shit = to_tenary(n);
	// cout << shit << endl;
	for(int i = 0; i < shit.size(); i++){
		if(shit[i] == '2')idx2 = i;
	}
	idx0 = shit.size();
	for(int i = shit.size() - 1; i >= idx2; --i){
		if(shit[i] == '0')idx0 = i;
	}
	// cout << idx2 << " " << idx0 << endl;
	if(idx2 == -1)res = n;
	else if(idx0 == shit.size())
		res = fpow(3, idx0);
	else{
		res += fpow(3, idx0);
		for(int i = idx0; i < shit.size(); i++){
			res += fpow(3, i) * (shit[i] - '0');
		}
	}
	printf("%lld\n", res);
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}