#include "bits/stdc++.h"
#define int long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

vector<int> sieve(int n){
	vector<bool> prime(n + 1, true);
	vector<int> ret;
	for(int p = 2; p*p <= n; p++){
		if(prime[p]){
			for(int i = p * p; i <= n; i+= p){
				prime[i] = 0;
			}
		}
	}
	for(int p = 2; p <= n; p++){
		if(prime[p])ret.push_back(p);
	}
	return ret;
}

int fpow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}

int32_t main(){
	int n, m = 0, res = 1, tot = 0;
	scan(n);
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		scan(arr[i]);
		m = max(m, arr[i]);
	}
	vector<int> prime = sieve(m);

	// for(int i = 0; i < n; i++)cout << arr[i] << ' ';
	// cout << endl;
	// cout << tot << endl;
	for(int p : prime){
		// cout << p << endl;
		int orz_marcus = LONG_MAX, orz_marcus_x2 = LONG_MAX;
		for(int& x : arr){
			int cnt = 0;
			while(x % p == 0){
				x /= p;
				// cout << x << " " << p << endl;
				cnt++;
			}
			if(cnt < orz_marcus){
				orz_marcus_x2 = orz_marcus;
				orz_marcus = cnt;
			}
			else if(cnt < orz_marcus_x2){
				orz_marcus_x2 = cnt;
			}
			// cout << endl;
			if(orz_marcus == 0 && orz_marcus_x2 == 0)break;
		}
		// cout << p << " " << illegal << endl;
		res *= fpow(p, orz_marcus_x2);
	}
	cout << res << endl;
	return 0;
}