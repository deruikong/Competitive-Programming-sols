#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;


int main(){
	int v1, v2, t, d;
	ll sum = 0;
	scan(v1);scan(v2);
	scan(t);scan(d);
	for(int i = 1; i <= t; i++){
		sum += min(v1 + (i - 1) * d, v2 + (t - i) * d);
	}
	cout << sum << endl;
	return 0;
}