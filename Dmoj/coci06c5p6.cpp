#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
ll N, base = 26, mod = 1e9 + 7, mod2 = 998244353;
string str;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

bool good(int len){
	ll h = 0, r = 1, h2 = 0, r2 = 1;
	unordered_set<ll, custom_hash> hashes;
	for(int i = 0; i < len - 1; i++){
		r = (r * base) % mod;
		r2 = (r2 * base) % mod2;
	}
	for(int i = 0; i < len; i++){
		h = (h * base + str[i]) % mod;
		h2 = (h2 * base + str[i]) % mod2;

	}
	hashes.insert((h << 32) + h2);
	for(int i = 1; i <= N - len; i++){
		h = (base * (h - str[i - 1] * r) + str[i + len - 1]) % mod;
		h2 = (base * (h2 - str[i - 1] * r2) + str[i + len - 1]) % mod2;
		if(h < 0) h += mod;
		if(h2 < 0)h2 += mod2;
		if(hashes.find((h << 32) + h2) != hashes.end())
			return true;
		hashes.insert((h << 32) + h2);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> str;
	int l = 0, h = N - 1;
	while(l < h){
		int mid = (l + h + 1) / 2;
		if(good(mid))l = mid;
		else h = mid - 1;
	}
	cout << l << endl;
	return 0;
}