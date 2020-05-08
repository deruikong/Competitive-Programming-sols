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
	for(int x = -10; x <= 10; x++){
        ///fpow(x*x - 5*x + 5, );
		cout << x << " " << x*x - 5*x + 5 << " " << x*x + 4*x - 60 <<  endl;
	}
	return 0;
}