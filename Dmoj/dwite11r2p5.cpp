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
    REP(i, 0, 4){
        int ch = 0, N;
        cin >> N;
        initSet(N);
        map<string, int> uwu;
        REP(i, 1, N){
            string cmd, u, v;
            cin >> cmd >> u >> v;
            if(uwu.find(u) == uwu.end())uwu[u] = ch++;
            if(uwu.find(v) == uwu.end())uwu[v] = ch++;
            if(cmd == "p")unionSet(uwu[u], uwu[v]);
            else if(findSet(uwu[u]) == findSet(uwu[v]))cout << "connected" << endl;
            else cout << "not connected" << endl;
        }
    }
    return 0;
}