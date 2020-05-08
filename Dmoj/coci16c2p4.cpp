//
// Created by RayKo on 2020-03-05.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

vector<pair<ll,ll>> p1;
vector<ll> h;
map<ll, vector<ll>> g;

ll binsearch(ll a, ll l, ll hi){
    ll ans = -1;
    while(l <= hi)
    {
        ll mid = l+(hi-l)/2;
        if(h[mid] >= a){hi = mid-1; ans = mid;}
        else l = mid+1;
    }

    return ans;
}

ll subs(ll a, ll l, ll hi, vector<ll> s){
    ll ans = -1;
    while(l <= hi)
    {
        ll mid = l+(hi-l)/2;
        if(s[mid] >= a){hi = mid-1; ans = mid;}
        else l = mid+1;
    }

    if(ans != -1) return s.size()-ans;
    return 0;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, tot = 0, bisect;
    cin >> n >> k;
    bisect = n/2;
    vector<vector<ll>> val(bisect, vector<ll>(3));
    vector<vector<ll>> valb(n-bisect, vector<ll>(3));

    ll a = 1UL << bisect;
    ll b = 1UL << (n-bisect);

    for(int i = 0; i < bisect; i++){
        cin >> val[i][0] >> val[i][1];
    }
    for(int i = 0; i<n-bisect; i++){
        cin >> valb[i][0] >> valb[i][1];
        h.push_back(valb[i][0]);
    }
    sort(h.begin(), h.end());
    for(int i = 0; i< h.size(); i++)g[h[i]] = {};
    for(ll i = 0; i < a; i++)
    {
        ll c = 0;
        ll h = 0;
        for(ll j = 0; j < bisect; j++)
        {
            if((i >> j) & 1){
                h = max(h, val[j][0]);
                c+= val[j][1];

                if(h > val[j][0]){
                    c = -1;
                    break;
                }
            }
        }
        if(c != -1)p1.emplace_back(h, c);
    }

    for(ll i = 1; i < b; i++)
    {
        ll c = 0;
        ll h = 0;
        ll m = 1e9+5;
        for(ll j = 0; j < n-bisect; j++)
        {
            if((i >> j) & 1){
                h = max(h, valb[j][0]);
                m = min(m, valb[j][0]);
                c+= valb[j][1];
                if(h > valb[j][0]){
                    c = -1;
                    break;
                }
            }
        }
        if(c != -1 && m != 1e9+5)g[m].push_back(c);
    }
    for(auto& x: g){
        sort(x.second.begin(), x.second.end());
    }
    for(auto & i : p1) {
        ll idx = binsearch(i.first, 0, h.size() - 1);
        if (i.second >= k) tot++;
        for (int j = idx; j < h.size(); j++) {
            if (i.second >= k) tot += g[h[j]].size();
            else tot += subs(k - i.second, 0, g[h[j]].size() - 1, g[h[j]]);
        }
    }
    cout << tot;
    return 0;
}