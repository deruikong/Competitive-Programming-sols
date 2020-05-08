#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int t;
	scan(t);
	while(t--){
		int n, maxr = 0, maxl;
		set<int> unique;
		scan(n);
		vector<int> cnt(n + 1, 0);
		for(int i = 0; i < n; i++){
			int cur;scan(cur);
			maxr = max(maxr, ++cnt[cur]);
			unique.insert(cur);
		}
		maxl = (int)unique.size() - 1;
		if(maxr - maxl >= 2)maxl++;
		printf("%d\n", min(maxr, maxl));
	}
	return 0;
}