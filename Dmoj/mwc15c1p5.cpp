#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

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
    string a, b;
    cin >> a >> b;
    int aa = 0, bb = 0;
    REP(i, 1, a.length()){
        int cpow = (tolower(a[i-1])-'a'+1)%10;
        aa += fpow(cpow, (i%4==0)?4:i%4);
        aa%=10;
    }    
    REP(i, 1, b.length()){
        int cpow = (tolower(b[i-1])-'a'+1)%10;
        bb += fpow(cpow, (i%4==0)?4:i%4);
        bb%=10;
    }
    if(aa==0)aa=10;
    if(bb==0)bb=10;
    cout << aa+bb;
    return 0;
}