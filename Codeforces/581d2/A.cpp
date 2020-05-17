#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
char _;

ull fpow(ull base, ull exp)
{
    ull result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}

int solve(string bs){
	int cnt = 0;
	cout << bs.size() << endl;
	
	for(int k = 0; k <= 50; k++){
		__int128 curr = (1ULL << (2 * k));
		if(curr < val)cnt++;
		else break;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string bs; cin >> bs;
	cout << solve(bs) << endl;
	return 0;
}