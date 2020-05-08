#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const ll MOD = 1000000013;

ll fpow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
        result %= MOD;
        base %= MOD;
    }
    return result%MOD;
}

ll mod(ll a, ll b) { return (a % b + b) % b; }

int main(){
	ll N, a, b, c, res = 0;
	cin >> N;
	if(N == 1){
		cout << 1 << endl;
		return 0;
	}
	a = fpow(2, N-2);
	b = fpow(2, N/2-1);
	c = N%8;
	if(c == 2 || c == 6) res = a;
	else if (c == 1 || c == 7 || c==0)res = a+b;
	else res = a-b;
	cout << mod(res, MOD) << endl;
	return 0;
}