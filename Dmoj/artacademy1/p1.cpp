#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
char _;
const int MN= 3e5 + 1; const ll MOD = 4294967296;
int N, M;
ll modinv;
vector<int> arr;

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x%m + m) % m; 
    return res;
} 
  
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

int dehash(ll val){
	ll cur = (val*modinv) % MOD;
	// cout << cur << endl;
	return cur;
}

int main(){
	ll sum = 0;
	modinv = modInverse(2654435761, MOD);
	// cout << modinv << endl;
	scan(N);scan(M);
	REP(i, 1, N){
		ll cur;
		scan(cur);
		arr.push_back(dehash(cur));
	}
	nth_element(arr.begin(), arr.begin() + M, arr.end(), greater<int>());
	REP(i, 0, M - 1){
		sum += arr[i];
	}
	cout << sum << endl;
	return 0;
}