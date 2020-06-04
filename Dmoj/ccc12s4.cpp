#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
set<vector<int>> vis;

ll init(int n){
	ll ret = 0;
	for(int i = n; i > 0; i--){
		ret *= 10; ret += i;
	}
	return ret;
}

ll fpow(ll base, ll exp){
	ll ret = 1;
	while(exp > 0){
		if(exp & 1) ret *= base;
		base *= base;
		exp >>= 1;
	}
	return ret;
}

ll vti(vector<int> arr){
	string ret;
	for(int i = 0; i < arr.size(); i++) ret += ' ';
	for(int i = 0; i < arr.size(); i++){
		ret[arr[i]] = i;
	}
	reverse(ret.begin(), ret.end());
	return stoll(ret);
}

vector<int> itv(ll x){
	string cur = to_string(x);

}

set<ll> vis;
void solve(int n){
	ll fin = init(n); vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	queue<pii> q; q.emplace(0, vti(arr));
	while(!q.empty()){
		int w = q.front().first; ll x = q.front().second; q.pop();
		if(x == fin){
			cout << w << endl;
			return;
		}
		vector<int> cur = itv(x);
		for(int i = 0; i < n; i++){
			if()
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	while(n != 0){
		vis.clear();
		solve(n);
		cin >> n;
	}
	return 0;
}