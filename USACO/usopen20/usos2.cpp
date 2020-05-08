#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, M, tot = 0;
vector<pii> cows;
int s[(int)1e5+1];
vector<int> vis((int)1e5+1, -1);
list<int> cereall[(int)1e5+1];
int cereal(int c){
    if(c==0 || s[c] != cows[c].first){
        for(int i = c; i < N; i++){
            if(vis[cows[i].first] == -1){
                vis[cows[i].first] = i;
                tot++;
                s[i] = cows[i].first;
            }
            else if(vis[cows[i].second] == -1){
                vis[cows[i].second] = i;
                tot++;
                s[i] = cows[i].second;
            }
        }
    }
    else{
        c--;
        tot--;
        cereall[s[c]].pop_front();
        if(cereall[s[c]].empty())vis[s[c]] = false;
        else{
            s[cereall[s[c]].front()] = s[c];
            tot++;
        }
    }
    return tot;
}

int main(){
    // freopen("cereal.in", "r", stdin);
    // freopen("cereal.out", "w", stdout);
    scanf("%d%d",&N, &M);
    memset(s, -1, sizeof(s));
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cows.emplace_back(--a,--b);
        cereall[a].push_back(i);
        cereall[b].push_back(i);
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", cereal(i));
    }
    return 0;
}