#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int MOD = 1e9 + 7;

int madd(int a, int b){return (a % MOD + b % MOD) % MOD;}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int bs = 0, ans = 0;
	string str; cin >> str;
	vector<int> cnt, original;
	reverse(str.begin(), str.end());
	for(auto ch : str){
		if(ch == 'b') bs++;
		else original.push_back(bs);
	}
	cnt.resize(original.size());
	cnt[0] = original[0];
	for(int i = 0; i < original.size(); i++){
		if(i != 0)cnt[i] = madd(original[i] - original[i - 1], cnt[i - 1] * 2);
		// cout << cnt[i] << endl;
		ans = madd(ans, cnt[i]);
	}
	cout << ans << endl;
	return 0;
}