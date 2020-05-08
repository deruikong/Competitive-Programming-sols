#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, K;
ll tot;
vector<int> cheese;

int main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i< N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        cheese.push_back(a-b);
        tot += a;
    }
    sort(cheese.rbegin(), cheese.rend());
    for(int i = 0; i<K; i++)tot -= cheese[i];
    printf("%lld\n", tot);
    return 0;
}