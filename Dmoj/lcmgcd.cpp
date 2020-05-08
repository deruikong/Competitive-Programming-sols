#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd( b, a% b);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i< t; i++){
        ll N, K;
        scanf("%lld%lld", &N, &K);
        if(N + K == 0){printf("0 0\n"); continue;}
        ll hcf = gcd(N, K);
        printf("%lld %lld\n", hcf, (N*K)/hcf);
    }
    return 0;
};
