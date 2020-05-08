#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;

struct edge{
    int u, v, w;
    bool operator<(edge const& other) const{
        return w < other.w;
    }
};

int N, M, tot;
vector<int> pset(100000);
vector<int> ss(100000);
//disjoint set funcs
void initSet(int size){pset.resize(size);REP(i,0, size-1) pset[i] = i, ss[i] = 1;}
int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
void unionSet(int i, int j){ss[findSet(j)]+=ss[findSet(i)], ss[findSet(i)] = 0;pset[findSet(i)] = findSet(j);tot--;}
bool sameSet(int i, int j){return findSet(i)==findSet(j);}
int setNum(){return ss.size();}
int sizeofSet(int i){return ss[i];}

int main(){
    int muda;
    scanf("%d%d%d", &N, &M, &muda);
    tot = N;
    initSet(N);
    vector<pii> edges;
    vector<edge> yeet;
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d%d%d", &u,&v, &w);
        yeet.push_back(edge{u, v, w});
    }
    sort(yeet.begin(), yeet.end());
    REP(i, 0, M-1){
        edge cur = yeet[i];
        if(findSet(cur.u) != findSet(cur.v)){
            unionSet(cur.u, cur.v);
            cout << cur.u <<" "<<cur.v << " " << cur.w << endl;
        }
    }
    return 0;
}