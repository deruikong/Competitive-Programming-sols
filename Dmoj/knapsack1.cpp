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
const int MM = 10e5 + 1;
int N, w;
ll ans[102][MM];
int main(){
	scan(N);scan(w);
	memset(ans, 0, sizeof(ans));
	REP(i, 1, N){
		int a, b;
		scan(a);scan(b);
		REP(j, 1, w){
			if(j >= a)
				ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - a] + b);
			else
				ans[i][j] = ans[i - 1][j];
		}
	}
	// REP(i, 1, N){
	// 	cout << i << endl;
	// 	REP(j, 1, w){
	// 		cout << ans[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans[N][w] << endl;
	return 0;
}