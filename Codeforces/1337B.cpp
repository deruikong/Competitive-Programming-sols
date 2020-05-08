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

void solve(int x, int n,int m){
	while((x/2+10) < x && n){
		x /= 2;
		x += 10;
		n--;
		//cout << x << endl;
	}
	if(x > m*10)printf("NO\n");
	else printf("YES\n");
}

int main(){
	int t;
	scan(t);
	while(t--){
		int x, n, m;
		scan(x);scan(n);scan(m);
		solve(x, n, m);
	}
	return 0;
}