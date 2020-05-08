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
int t, N, tot;

int main(){
	scan(t);
	while(t--){
		tot = 0;
		scan(N);
		vector<int> arr(N + 1);
		REP(i, 1, N){
			scanf("%d", &arr[i]);
		}
		REP(i, 2, N){
			int cnt = 0;
			if(arr[i] > arr[i - 1])continue;
			int left = arr[i - 1] - arr[i];
			while(left){
				left >>= 1;
				cnt++;
			}
			tot = max(tot, cnt);
			arr[i] = arr[i - 1];
		}
		printf("%d\n", tot);
	}	
	return 0;
}