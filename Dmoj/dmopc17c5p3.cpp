#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

ll gcd(ll a, ll b) {if (b == 0) return a; return gcd(b, a % b);}

void prime(ll n){
    ll greatest = -1;
    while(n%2 == 0){
        n/=2;
        greatest = 2;
    }
    for(ll i = 3; i*i <= n; i++){
        while(n%i == 0){
            greatest = i;
            n /= i;
        }
    }
    if(n > 2)greatest = n;
    if(greatest== -1) printf("DNE");
    else printf("%lld", greatest);
}

int main(){
    int N;
    ll G = -1;
    scanf("%d", &N);
    vector<ll> arr(N);
    REP(i, 0, N-1){
        scanf("%lld", &arr[i]);
        if(G == -1)G = arr[i];
        G = gcd(G, arr[i]);
    }
    prime(G);
    return 0;
}