// #include <bits/stdc++.h>
// #define INF 0x3f3f3f3f
// #define ll long long
// #define ull unsigned long long
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define pdd pair<double, double>
// #define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
// using namespace std;
// int N, M, D;
// //disjoint set funcs
// struct edge{
//     int u, v, w, i;
//     bool operator<(const edge& rhs)const {
//         return tie(u, v) < tie(rhs.u, rhs.v);
//     }
//     bool operator==(const edge& rhs)const {
//         return (tie(u, v) == tie(rhs.u, rhs.v) && w == rhs.w);
//     }
// };

// bool comp(edge a, edge b){return a.w < b.w || (a.w==b.w&&a.i<b.i);}

// vector<edge> edges(5000);
// vector<int> pset(100000);
// vector<int> ss(100000);
// void initSet(int size){pset.resize(size);REP(i,0, size-1) pset[i] = i, ss[i] = 1;}
// int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
// void unionSet(int i, int j){ss[findSet(j)]+=ss[findSet(i)], ss[findSet(i)] = 0;pset[findSet(i)] = findSet(j);}
// bool sameSet(int i, int j){return findSet(i)==findSet(j);}
// int setNum(){return ss.size();}
// int sizeofSet(int i){return ss[i];}

// int main(){
//     int tot = 0, max_weight;
//     ll weight;
//     scanf("%d%d%d", &N, &M, &D);
//     set<edge> origin;
//     vector<edge> MST;
//     edges.resize(M);
//     initSet(N);
//     REP(i, 0, M-1){
//         int u, v, w;
//         scanf("%d%d%d", &u, &v, &w);
//         if(i < N-1)origin.insert(edge{u, v, w, i});
//         edges[i] = edge{u, v, w, i};
//     }
//     sort(edges.begin(), edges.end(), comp);
//     int ee = 0, i;
//     for(int k = 0; k < M; k++){
//         if(ee == N-1)i = k;
//         edge cur = edges[k];
//         if(findSet(cur.u) != findSet(cur.v)){
//             ee++;
//             unionSet(cur.u, cur.v);
//             MST.push_back(cur);
//             max_weight=max(max_weight, cur.w);
//         }
//     }
//     sort(MST.begin(), MST.end());
//     REP(i, 0, N-1){
//         if(origin.find(MST[i]) == origin.end())tot++;
//     }
//     // if(origin.find(edges[i-1])!=origin.end()){
//     //     initSet(N-1);
//     //     for(auto&x : edges){
//     //         bool old = origin.find(x)!=origin.end();
//     //         if(findSet(x.u) != findSet(x.v)){
//     //             if(x.w < max_weight || (x.w == max_weight && old)){
//     //                 unionSet(x.u, x.v);
//     //             }
//     //             else if(old && x.w <= D){
//     //                 tot--;
//     //                 break;
//     //             }
//     //         }
//     //     }
//     // }
//     printf("%d", tot);
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int N, M, D;
//disjoint set funcs
struct edge{
    int u, v, w, i;
    bool operator<(const edge& rhs)const {
        return tie(u, v, w, i) < tie(rhs.u, rhs.v, rhs.w, rhs.i);
    }
    bool operator==(const edge& rhs)const {
        return (tie(u, v) == tie(rhs.u, rhs.v) && w == rhs.w);
    }
};

bool comp(edge a, edge b){return a.w < b.w || (a.w==b.w&&a.i<b.i);}

vector<edge> edges;
vector<int> pset(100000);
vector<int> ss(100000);
void initSet(int size){pset.resize(size);REP(i,0, size-1) pset[i] = i, ss[i] = 1;}
int findSet(int i){return (pset[i]==i)?i:(pset[i]=findSet(pset[i]));}
void unionSet(int i, int j){ss[findSet(j)]+=ss[findSet(i)], ss[findSet(i)] = 0;pset[findSet(i)] = findSet(j);}
bool sameSet(int i, int j){return findSet(i)==findSet(j);}
int setNum(){return ss.size();}
int sizeofSet(int i){return ss[i];}

int main(){
    int tot = 0, max_weight;
    ll weight;
    scanf("%d%d%d", &N, &M, &D);
    initSet(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(edge{--u, --v, w, (i<N-1)?0:1});
    }
    sort(edges.begin(), edges.end(), comp);
    int e = 0, i;
    REP(k, 0, M-1){
        if(e == N-1)i=k;
        edge cur = edges[k];
        if(findSet(cur.u) != findSet(cur.v)){
            e++;
            unionSet(cur.u, cur.v);
            tot += cur.i;
            max_weight=cur.w;
            i = cur.i;
        }
    }
    if(D && i){
        initSet(N);
        for(auto&x : edges){
            if(findSet(x.u) != findSet(x.v)){
                if(x.w < max_weight || (x.w == max_weight && !x.i)){
                    unionSet(x.u, x.v);
                }
                else if(!x.i && x.w <= D){
                    printf("%d", --tot);
                    return 0;
                }
            }
        }
    }
    printf("%d", tot);
    return 0;
}