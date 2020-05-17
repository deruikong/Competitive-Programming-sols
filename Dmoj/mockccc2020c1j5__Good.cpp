#include "bits/stdc++.h"
#define scan(i) do{while((i=getchar())<'0'); for(i-='0'; '0'<=(_=getchar()); i=(i<<3)+(i<<1)+_-'0');}while(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char _;

bool prime(ll cur){
    if(cur == 1) return false;
    if(cur == 2) return true;
    for(ll i = 2; i*i <= cur; i++){
        if(cur % i == 0) return false;
    }
    return true;
}

ll next_prime(ll i){
    while(!prime(i)){
        i++;
    }
    return i;
}

ll fpow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }
    return result;
}
int main()
{
    int d, n;
    scanf("%i%i", &d, &n);
    ll lo = next_prime(fpow(10, d - 1));
    string s = to_string(n);
    ll mi = LONG_MAX;
    if (d > s.length())
        return 0 * printf("%lli%lli\n", lo, lo);
    for (int i = 0; i <= s.length() - d; i++)
    {
        int pref = i ? stoi(s.substr(0, i)) : 0;
        int suf = -1;
        if (i < d)
            pref = lo, suf = next_prime(fpow(10, s.length()-i-1));
        else if (prime(pref))
        {
            suf = stoi(s.substr(i, s.length()));
            suf = max((ll)suf, fpow(10, s.length()-i-1));
            suf = next_prime(suf);
            mi = min(mi, stoll(to_string(pref) + to_string(suf)));
            ++pref;
        }
        if (i >= d)
        {
            pref = next_prime(pref);
            suf = next_prime(fpow(10, s.length()-i-1));
        }
        ll cur = stoll(to_string(pref) + to_string(suf));
        mi = min(mi, cur);
        // cout << i << " " << cur << endl;
    }
    printf("%lli\n", mi);
}