#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
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

ll gp(int f, int p) 
{ 
    ll res = 0;
    int i = 1;
    while(f/fpow(p, i)){
        res += f/fpow(p, i);
        i++;
    }
    return res;
}

  

int main() 
{ 
    int a,b;
    cin >> a >> b;
    ll res = INT_MAX; 
    for (ll i = 2; i <= sqrt(a); i++) {
        int c = 0; 
        if (a % i == 0) { 
            c++; 
            a /= i;
        }
        if (c > 0) { 
            ll cp = gp(b, i)/c;
            if(i == a){
                cp /= 2;
            }
            res = min(res, cp); 
        }
    }
    if (a >= 2) { 
        ll cp  = gp(b, a);
        res = min(res, cp);
    }
    cout << res << endl;
    return 0; 
}