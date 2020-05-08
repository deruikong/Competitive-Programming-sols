#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
const int MOD = 1e9 + 7;
ll madd(ll a, ll b){return (a + b)%MOD;}

char _;
const int MAXN = 5e5 + 10;
string s;
int N, M;
int ppow[MAXN] = {1};
// dset
int pset[MAXN];
int findSet(int u){return (pset[u] == u)?u:(pset[u] = findSet(pset[u]));}
void unionSet(int u, int v){pset[findSet(u)] = findSet(v);}

int main(){
    scan(N);scan(M);
    cin >> s;
    REP(i, 1, N-1){
        ppow[i] = madd(ppow[i - 1], ppow[i - 1]);;
    }
    reverse(ppow, ppow + N);
    iota(pset, pset + MAXN, 0);
    ll ans = 0;
    REP(i, 0, N-1){
        if(s[i] == '1'){
            unionSet(i, i + 1);
            ans = madd(ans, ppow[i]);
        }
    }
    REP(i, 1, M){
        int l, r;
        scan(l);scan(r);
        l--, r--;
        l = findSet(l);
        //cout << l << endl;
        while(l <= r){
            int c = findSet(l + 1);
            //cout << l << endl;
            ans = madd(ans, ppow[l]);
            unionSet(l, c);
            l = c;
        }
        //cout << endl;
        printf("%d\n", ans);
    }
    return 0;
}