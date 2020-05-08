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


int main(){
	int n;
	cin >> n;
	REP(i, 1, n){
		ll a, b, t;
		cin >> a >> b >> t;
		if(a*b == t)cout << "POSSIBLY DOUBLE SIGMA" << endl;
		else cout << "16 BITS S/W ONLY" << endl;
	}
	return 0;
}