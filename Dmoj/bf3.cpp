#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;


int main(){
    ll N;
    scanf("%lld", &N);
    if(N < 2)N = 2;
    while(true){
        bool isPrime = true;
        for(ll i = 2; i*i <= N; i++){
            if(N%i == 0){
                N++;
                isPrime = false;
                break;
            }
        }
        if(isPrime){printf("%lld", N);break;}
    }
    return 0;
}