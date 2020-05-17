#include "bits/stdc++.h"
#define scan(i) do{while((i=getchar())<'0'); for(i-='0'; '0'<=(_=getchar()); i=(i<<3)+(i<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

bool prime(ll cur){
	if(cur == 1) return false;
	if(cur == 2) return true;
	for(ll i = 2; i*i <= cur; i++){
		if(cur % i == 0) return false;
	}
	return true;
}

ll next_prime(ll i){
	while(!prime(i)){
		i++;
	}
	return i;
}

ll fpow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}
int main(){
	int D, N;
	ll res = LLONG_MAX; string str;
	cin >> D >> N;
	str = to_string(N);
	if(D * 2 > str.size()){
		ll m = next_prime(fpow(10, D - 1));
		cout << m << m << endl;
		return 0;
	}
	for(int i = D; i <= str.size() - D; i++){
		int pref = stoi(max(str.substr(0, i), to_string(0)));
		int suff = -1;
		if(prime(pref)){
			suff = next_prime(max(stoll(str.substr(i)), fpow(10, str.length() - i - 1)));
			res = min(res, stoll(to_string(pref) + to_string(suff)));
			pref++;
		}
		// cout << pref << endl;
		pref = next_prime(pref);
		suff = next_prime(fpow(10, str.length() - i - 1));
		res = min(res, stoll(to_string(pref) + to_string(suff)));
	}
	cout << res << endl;
	return 0;
}