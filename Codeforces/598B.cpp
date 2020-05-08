#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
int q;
string str;

int newpos(int i, int l, int r, int t){
	if(i + t <= r) return i + t;
	else return l + (i + t - r - 1);
}

void shift(int l, int r , int t){
	string cur_str = str;
	for(int i = l; i <= r; i++){
		cur_str[newpos(i, l, r, t)] = str[i];
	}
	str = cur_str;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> str;
	cin >> q;
	while(q--){
		int l, r, t;
		cin >> l >> r >> t;
		--l, --r, t %= r - l + 1;
		shift(l, r, t);
		//cout << str << endl;
	}
	cout << str << endl;
	return 0;
}