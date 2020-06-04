#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
vector<int> pset(100001);
void initSet(int size){pset.resize(size);REP(i, 0, size-1)pset[i] = i;}
int findSet(int i){return (pset[i] == i)?i:(pset[i] = findSet(pset[i]));}
void unionSet(int u, int v){pset[findSet(u)] = findSet(v);}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ch = 0, N, Q;
    cin >> Q >> N;
    initSet(Q+1);
    REP(i, 1, N){
        string cmd;
        int u, v;
        cin >> cmd >> u >> v;
        if(cmd == "A")unionSet(u, v);
        else if(findSet(u) == findSet(v))cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}