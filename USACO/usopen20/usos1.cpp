#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
using namespace std;
int D, N, M;
vector<pll> ints;

bool good(ll dis){
    ll prev;
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        if(i == 0)prev = ints[0].fi;
        else if(prev+dis > ints[idx].se){
            if(prev+dis <= ints[idx+1].fi)prev = ints[++idx].fi;
            else{
                int lo = idx, hi = M-1, best = INT_MAX;
                for(int i = 0; i < 20 && lo <= hi; i++){
                    int mid = lo+(hi-lo)/2;
                    if(ints[mid].se >= prev+dis){
                        best = min(mid, best);
                        hi = mid;
                    }
                    else{
                        lo = mid+1;
                    }
                }
                if(best == INT_MAX)return false;
                else idx = best;
                prev = max(prev+dis, ints[idx].fi);
            }
        }
        else prev += dis;
    }
    return true;
}

int main(){
    freopen("D:/Ray/C/Competitive/USACO/usopen20/socdist.in", "r", stdin);
    //freopen("socdist.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        pll cur;
        scanf("%lld%lld", &cur.fi, &cur.se);
        ints.push_back(cur);
    }
    sort(ints.begin(), ints.end());
    ll lo = 0, hi = ints.back().se +1;
    for(int i = 0; i< 100 && lo < hi; i++){
        ll mid = (lo+hi)/2;
        if(good(mid))lo = mid;
        else hi = mid-1;
    }
    ll best = lo;
    for(int i = 0; i < 20; i++){
        if(good(lo+i)) best = lo+i;
    }
    printf("%lld", best);
    cin >> N;
    return 0;
}