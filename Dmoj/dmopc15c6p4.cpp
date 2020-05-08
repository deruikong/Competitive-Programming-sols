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

struct edge{
    int u, v, w;
    bool operator<(edge const& other)const{
        return w < other.w;
    }
};

using namespace std;
int N, K;
vector<int> pset(100001);
vector<int> ss(100001);
void initSet(int size){pset.resize(size);REP(i,0, size-1) pset[i] = i, ss[i] = 1;}
int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
void unionSet(int i, int j){pset[findSet(i)] = findSet(j);ss[findSet(j)] += ss[findSet(i)];}
bool sameSet(int i, int j){return findSet(i)==findSet(j);}
vector<edge> edges;

int main(){
    int tot = 0;
    scanf("%d%d", &N, &K);
    initSet(N);
    REP(i, 1, N-1){
        int w;
        scanf("%d", &w);
        edges.push_back(edge{i, i+1, w});
        if(i+K <= N)edges.push_back(edge{i, i+K, 0});
    }
    sort(edges.begin(), edges.end());
    for(edge cur: edges){
        if(!sameSet(cur.u, cur.v)){
            tot+=cur.w;
            unionSet(cur.u, cur.v);
        }
    }
    cout << tot << endl;
    return 0;
}