#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N;
vector<ll> sums(4004, 0);
vector<ll> a(2002, 0);


int main(){
    scanf("%d", &N);
    REP(i, 0, N-1){
        int c;
        scanf("%d", &c);
        a[c]++;
    }
    REP(i, 1, 2000){
        if(a[i]){
            REP(j, i, 2000){
                if(i == j)sums[i+j] += a[i] >> 1;
                else sums[i+j] += min(a[i], a[j]);
            }
        }
    }
    ll a1 = 0, a2 = 0;
    REP(i, 2, 4000){
        if(sums[i] > a1){
            a1 = sums[i];
            a2 = 1;
        }
        else if(sums[i] == a1){
            a2++;
        }
    }
    printf("%lld %lld", a1, a2);
    return 0;
}