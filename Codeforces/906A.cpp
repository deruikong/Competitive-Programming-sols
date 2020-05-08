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
int N, final;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bitset<26> left, cur;
	left.set();
	cin >> N;
	REP(i, 1, N - 1){
		int stat;
		cur.reset();
		string op, let; cin >> op >> let;
		final += left.count() == 1 && op != ".";
		if(op == "!")stat = 1;
		else stat = 0;
		REP(i, 0, let.size()-1){
			cur[let[i]-'a'] = 1;
		}
		if(stat)left &= cur;
		else{
			REP(i, 0, 25){
				left[i] = left[i]?(left[i]^cur[i]):left[i];
			}
		}
		// cout << left.to_string() << endl << cur.to_string() << endl << final << endl << endl;
	}
	cout << final << endl;
	return 0;
}