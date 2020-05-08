// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define d 256
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n, h;
    int nl, hl, tot = 0;
    const int arrLen = 26;
    int N[arrLen] = {0}, H[arrLen] = {0};
    ll q = 1000000007,q1 = 998244353, m = 1, m1 = 1;
    ll t = 0, t1 = 0;
    set<pair<int,int>> p;
    cin >> n >> h;
    nl = n.length();
    hl = h.length();
    if(nl <= hl){
        for (int i = 0; i < nl - 1; i++){m = (m * d) % q;m1 = (m1 * d) % q1;}
        for(int i = 0; i < nl; i++){
            H[h[i]-'a']++;
            N[n[i]-'a']++;
            t = (t*d+h[i])%q;
            t1 = (t1*d+h[i])%q1;
        }
        for(int i = 0; i < hl-nl+1; i++){
            if(i != 0){
                H[h[i-1]-'a']--;
                H[h[i+nl-1]-'a']++;
                t = (d*(t - h[i-1]*m) + h[i+nl-1])%q;
                t1 = (d*(t1 - h[i-1]*m1) + h[i+nl-1])%q1;
                if (t < 0)t = (t + q);
                if(t1 < 0)t1 = (t1+q1);
            }

            if(p.find(make_pair(t,t1)) != p.end()) continue;
            p.insert(make_pair(t,t1));
            int j;
            for(j = 0; j < 26; j++){
                if(H[j]!=N[j])break;
            }
            if(j == 26){
                tot++;
            }
        }
    }
    cout << tot;

    return 0;
}
