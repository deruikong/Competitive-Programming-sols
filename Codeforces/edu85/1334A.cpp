#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int T, N;

int main(){
	scan(T);
	while(T--){
		bool res = true;
		pii prev = make_pair(0, 0);
		scanf("%d", &N);
		//cout << N << endl;
		for(int i = 0; i < N; i++){
			pii cur;
			scanf("%d%d", &cur.first, &cur.second);
			//cout << cur.first << " " << cur.second << endl;
			if(cur.second < prev.second || cur.first < prev.first  || (cur.second - prev.second > cur.first - prev.first)){
				//cout << (cur.second < prev.second) << (prev.first > cur.first) <<  (cur.second > prev.second && cur.first <= prev.first) << endl;
				//cout << cur.first << " " << cur.second << endl;
				//cout << prev.first << " " << prev.second << endl;
				res = min(res, false);
			}
			prev = cur;
		}
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
		//cout << endl;
	}
	return 0;
}