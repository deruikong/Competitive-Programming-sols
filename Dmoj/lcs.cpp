#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int subs[1001][1001];

int main(){
    int N, M, tot = 0;
    memset(subs, 0, sizeof(subs));
    scanf("%d%d", &N, &M);
    vector<int> firsts(N+1);
    REP(i, 1, N)scanf("%d", &firsts[i]);
    REP(i, 1, M){
        int cur;
        scanf("%d", &cur);
        REP(j, 1, N){
            if(cur==firsts[j])subs[i][j]=subs[i-1][j-1]+1;
            else subs[i][j] = max(subs[i-1][j], subs[i][j-1]);
        }
    }
    printf("%d", subs[M][N]);
    return 0;
}