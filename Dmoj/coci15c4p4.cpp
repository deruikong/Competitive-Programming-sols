//
// Created by RayKo on 2020-03-10.
//
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll N, K, Q;

ll d(ll a, ll b){
    if(K == 1) return abs(a-b);
    ll ans = 0;
    while(a != b){
        if(a > b)swap(a, b);
        b = (b-1)/K;
        ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> Q;
    //get tree levels
    //algos
    for(int i = 0; i< Q; i++){
        ll nodeA, nodeB;
        cin >> nodeA >> nodeB;
        cout << d(nodeA-1, nodeB-1) << endl;
    }
    return 0;
}


