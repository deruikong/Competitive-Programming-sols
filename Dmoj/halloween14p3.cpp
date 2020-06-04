#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 5e3 + 5;
const ll base = 26, mod = 1e9 + 7;
ll rep[mn], beg[mn];

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

unordered_set<ll> magic;
int n, cnt;
char str[mn];

char* substr(const char *src, int m, int n)
{
	int len = n - m;
	char *dest = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = m; i < n && (*(src + i) != '\0'); i++)
	{
		*dest = *(src + i);
		dest++;
	}*dest = '\0';
	return dest - len;
}

int go(int len){
	int ret = 0;
	// cout << len << endl;
	ll hsh = beg[len], r = rep[len - 1];
	vector<ll> hs(n + 1);
	for(int i = len - 1; str[i] != '\0'; i++){
		if(i >= len){
			hsh = (base * (hsh - str[i - len] * r) + str[i]) % mod;
			if(hsh < 0) hsh += mod;
		}hs[i] = hsh;
		// cout << substr(str, i - len + 1, i + 1) << " " << hsh << endl;
	}
	for(int i = len - 1; str[i] != '\0';i++){
		ll hsh = hs[i], o = hsh, alt;
		int idx = i, a = idx, t = 1;
		// orz mathchadyang
		while(idx + len < n){
			if(o != hs[idx + len])break;
			// for(int j = idx + 1; j <= idx + len; j++){
			// 	hsh = (hsh * base + str[j]) % mod;
			// }
			idx += len;
			t++;
			alt = (beg[idx + 1] - beg[a - len + 1] * rep[t * len]) % mod;
			if(alt < 0) alt += mod;
			// cout << a - len + 1 << " " << substr(str, 0, a - len + 1) << " " << idx << " " << alt << " " << hsh << endl;
			if(magic.find(alt) != magic.end()) continue;
			// cout << substr(str, a - len + 1, idx + 1) << " " << hsh << endl;
			ret++;
			magic.insert(alt);
		}
	}
	// cout << endl;
	return ret;
}

int main(){
	rep[0] = 1;
	scanf("%s", &str);
	n = strlen(str);
	for(int i = 1; i <= n; i++){
		rep[i] = (rep[i - 1] * base) % mod;
		beg[i] = (beg[i - 1] * base + str[i - 1]) % mod;
		// cout << beg[i] << " " << rep[i] << endl;
		// cout << i << " " << beg[i] << endl;
	}
	for(int i = 1; i*2 <= n; i++){
		cnt += go(i);
	}
	printf("%d\n", cnt);
	return 0;
}