#include "bits/stdc++.h"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

int fpow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}


int main(){
	srand(chrono::steady_clock::now().time_since_epoch().count());
	ll a = max(1, rand() % 5), b = (rand() * rand())%fpow(10, a * 2 + 1);
	cout << a << " " << b << endl;
	return 0;
}