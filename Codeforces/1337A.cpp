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


int main(){
	int t;
	scan(t);
	while(t--){
		int a, b, c, d;
		scan(a);scan(b);scan(c);scan(d);
		int a1 = b, a2 = c, a3 = c;
		printf("%d %d %d\n", a1, a2, a3);
	}
	return 0;
}