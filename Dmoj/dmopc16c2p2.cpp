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
vector<int> ss(100001);
void initSet(int size){pset.resize(size+1);REP(i, 1, size) pset[i] = i, ss[i] = 1;}
int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
void unionSet(int i, int j){ss[findSet(j)]+=ss[findSet(i)], ss[findSet(i)] = 0;pset[findSet(i)] = findSet(j);}
bool sameSet(int i, int j){return findSet(i)==findSet(j);}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ch = 0, N, Q;
    cin >> N >> Q;
    initSet(N);
    REP(i, 1, Q){
        int t, prev, cur;
        cin >> t;
        cin >> prev;
        REP(j, 2, t){
            cin >> cur;
            if(findSet(prev)!=findSet(cur))unionSet(prev, cur);
            prev = cur;
        }
    }
    cout << ss[findSet(1)] << endl;
    REP(i, 1, N){
        if(findSet(i) == findSet(1))cout << i <<" ";
    }
    return 0;
}