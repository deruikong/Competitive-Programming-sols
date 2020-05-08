#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int n;
ll l, r;
vector<int> ans;

bool inside(ll idx){
	return l <= idx && idx < r;
}

bool intersect(ll l1, ll r1, ll l2, ll r2) {
	return min(r1, r2) > max(l1, l2);
}

void go(int b, int e, ll& num){
	if(b == e) return;
	//cout << b << " " << e << endl;
	if(intersect(l, r, num, num + (e - b) * 2)){
		//cout << intersect(num) << " " << num + (e - b) * 2 << endl;
		for(int i = b + 1; i < e + 1; i++){
			if(inside(num)){
				ans.push_back(b);
			}
			num++;
			if(inside(num)){
				ans.push_back(i);
			}
			num++;
			//cout << num << endl;
		}
	}
	else{
		num += (e - b) * 2;
	}
	go(b + 1, e, num);
	if(b == 1 && inside(num)){
		ans.push_back(b);
		num++;
	}
}


void solve(){
	ans.clear();
	scanf("%d%lld%lld", &n, &l, &r);
 	ll id = 1;
 	r++;
	go(1, n, id);
	for(int i : ans){
		printf("%d ", i);
	}
	printf("\n");
}

int main(){
	int t;
	scan(t);
	while(t--){
		solve();
	}
	return 0;
}