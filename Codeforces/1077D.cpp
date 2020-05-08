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
const int MN = 2e5 + 1;
int N, K, ans;
vector<int> arr(MN), cnt(MN);

int main(){
	scan(N);scan(K);
	arr.resize(N);
	REP(i, 0, N -1){
		scan(arr[i]);
		cnt[arr[i]]++;
	}
	printf("%d", ans);
	return 0;
}