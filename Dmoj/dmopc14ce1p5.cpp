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
struct teacher{
	int h, e, p;
};
int N;
teacher t[52];
pii dp[52][1002];

int main(){
	scan(N);
	REP(i, 1, N){
		scan(t[i].h);scan(t[i].e);scan(t[i].p);
	}
	scan(s);
	REP(i, 1, N){
		teacher curr = t[i];
		REP(j, 0, s){
			for(int a = j; a >= 0 && curr.h >= 0; )
		}
	}
	return 0;
}