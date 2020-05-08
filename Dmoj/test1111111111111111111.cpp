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
struct t{
	int h, p;
};


int N, s;
pii dp[2][1001];
vector<t> arr;

void go(int h, int e, int p){
	while(h > 0){
		arr.push_back(t{h, p});
		h -= e;
	}
}

int main(){
	scan(N);
	REP(i, 1, N){
		int h, e, p;
		scan(h);scan(e);scan(p);
		go(h, e, p);
	}
	scan(s);

	REP(i, 0, arr.size() - 1){
		int a = arr[i].p, b = arr[i].h;
		// cout << curr.h << endl;
		REP(j, 1, s){
			if(j >= a){
				dp[i%2][j] = max(dp[(i + 1)%2][j], dp[(i + 1)%2][j - a] + b);
				if(dp[(i + 1)%2][j] == dp[(i + 1)%2][j - a] + b){
					cnt[i%2][j] = min(cnt[(i + 1)%2][j], cnt[(i + 1)%2][j - a] + 1);
				}
				else if(dp[(i + 1) %2][j] < dp[(i + 1)%2][j - a] + b){
					cnt[i%2][j] = cnt[(i + 1)%2][j - a] + 1;
				}
				else{
					cnt[i%2][j] = cnt[(i + 1)%2][j];
				}
			}
			else{
				dp[i%2][j] = dp[(i + 1)%2][j];
			}
		}
	}
	// REP(i, 1, s){
	// 	cout << i << " " << dp[0][i] << endl;
	// }
	printf("%d\n%d", dp[(arr.size() - 1) % 2][s], cnt[(arr.size() - 1) % 2][s]);
	return 0;
}