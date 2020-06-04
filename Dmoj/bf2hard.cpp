#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;
const int mn = 1e6 + 5, base = 131, MOD = 1e9 + 7;
int N, fin,
	hs[mn], ppow[mn];
string str;

int qry(int l, int len){
	return (((hs[l + len] - hs[l] * ppow[len]) % MOD) + MOD) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ppow[0] = 1;
	for(int i = 1; i <= (int)1e6; i++){
		ppow[i] = (ppow[i - 1] * base) % MOD;
		hs[i] = (hs[i - 1] * base + str[i - 1]) % MOD;
	}
	cin >> str >> N;

	return 0;
}