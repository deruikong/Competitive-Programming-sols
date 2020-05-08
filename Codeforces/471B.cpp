#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int n, tot = 1;
	scan(n);
	vector<pii> orders(n);
	set<int> repeated;
	set<pii> swaped;
	for(int i = 0; i < n; i++){
		scan(orders[i].first);
		orders[i].second = i + 1;
		if(repeated.count(orders[i].first))tot++;
		repeated.insert(orders[i].first);
	}
	if(tot < 3)printf("NO\n");
	else{
		printf("YES\n");
		sort(orders.begin(), orders.end());
		for(int i = 0; i < 3; i++){
			bool yes = true;
			for(int j = 0; j < n; j++){
				printf("%d ", orders[j].second);
				if(yes && j != 0 && orders[j].first == orders[j - 1].first && !swaped.count(make_pair(orders[j - 1].second, orders[j].second))){
					swap(orders[j], orders[j - 1]);
					yes = false;
					swaped.insert(make_pair(orders[j - 1].second, orders[j].second));
				}
			}
			printf("\n");
		}
	}
	return 0;
}