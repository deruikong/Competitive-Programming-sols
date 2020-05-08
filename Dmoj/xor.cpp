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

int fxor(int n){
	switch(n & 3){
		case 0: return n;
		case 1: return 1;
		case 2: return n+1;
		case 3: return 0;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	REP(i, 1, T){
		int a, b;
		cin >> a >> b;
		cout << (fxor(b)^fxor(a-1)) << endl;
	}
	return 0;
}