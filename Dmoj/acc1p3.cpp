//
// Created by RayKo on 2020-03-17.
//

//#include <bits/stdc++.h>
//#define ll long long int
//#define pii pair<ll,ll>
//#define INF 0x3f3f3f3f
//using namespace std;
//ll MAX = 0, N;
//ll D;
//vector<pii> poutine(1e5, make_pair(0,INF));
//
//ll check(ll a){
//    ll tot = 0, ords = 0;
//    for(int i = 0; i < N; i++){
//        if(poutine[i].first >= a)
//        {
//            ll b = (poutine[i].first - a) / poutine[i].second + 1;
//            if(tot+b < 0)return D+1;
//            tot += b;
//        }
//    }
//    if(tot == D)MAX = max(ords, MAX);
//    return tot;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> N >> D;
//    ll m = 0;
//    for(int i = 0; i<N; i++){cin >> poutine[i].first >> poutine[i].second;m=max(m,poutine[i].first);poutine[i].first%=998244353;}
//
//    ll L = 0, H = m+1;
//    while(L+1 < H){
//        ll mid = (L+H)/2;
//        ll cur = check(mid);
//        if(cur >= D)L=mid;
//        else H = mid;
//    }
//    ll tot = 0;
//    for(int i = 0; i < N; i++){
//        ll times = min(((poutine[i].first - L) / poutine[i].second + 1), D);
//        times %= 998244353;
//        ll ordmin = poutine[i].first-poutine[i].second*(times-1);
//        tot += (times*(ordmin+poutine[i].first))/2;
//        tot %= 998244353;
//        D-=times;
//    }
//    cout << tot << endl;
//    return 0;
//}
#include <bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define INF 0x3f3f3f3f
using namespace std;
ll MAX = 0, N;
ll D;
vector<pii> poutine(1e5+1, make_pair(0,INF));
ll check(ll a){
    ll tot = 0, ords = 0;
    for(int i = 0; i < N; i++){
        if(poutine[i].first >= a)
        {
            ll b = (poutine[i].first - a) / poutine[i].second + 1;
            tot += b;
            ords+=(b*(poutine[i].first+(poutine[i].first- poutine[i].second*(b-1))))/2;
            ords%=998244353;
        }
    }
    if(tot == min(a,D))MAX = max(ords, MAX%998244353);
    return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> D;
    ll m = 0;
    for(int i = 0; i<N; i++){cin >> poutine[i].first >> poutine[i].second;m=max(m,poutine[i].first);poutine[i].first%=998244353;}

    ll L = 0, H = m+1;
    while(L+1 < H){
        ll mid = (L+H)/2;
        ll cur = check(mid);
        if(cur >= D)L=mid;
        else H = mid-1;
    }
    if(MAX == 0){cout << N <<"," << D << endl;for(int i = 0; i < N; i++)cout << poutine[i].first <<":"<<poutine[i].second << endl;}
    cout << MAX << endl;
    return 0;
}