#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
ll last, cnt;
set<int> wins[2];

bool solve(ll q, bool team){
	if(wins[0].count(q)){
		return team ^ 1;
	}
	else if(wins[1].count(q)){
		return team;
	}
	cnt++;
	// cout << q << endl;
	bool win = false, yes = false;
	for(ll i = 2; i * i <= q; i++){
		// cout << q%i << endl;
		if(q % i == 0){
			yes = true;
			if(solve(q/i, team ^ 1) == team){
				// cout << " yes " << endl;
				win = true;
				last = q/i;
			}
			else if(solve(i, team ^ 1) == team){
				// cout << " no " << endl;
				win = true;
				last = i;
			}
		}
	}
	if(win || !yes){
		wins[1].insert(q);
	}
	else{
		wins[0].insert(q);
	}
	return (win || !yes)?team : team ^ 1;
}

int main(){
	ll q;
	scan(q);
	bool res = solve(q, 1);
	if(!res){
		printf("2\n");
	}
	else{
		printf("1\n%I64d\n", last);
	}
	// cout << cnt << endl;
	return 0;
}