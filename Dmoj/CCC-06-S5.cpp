#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int N, M, a, b, c, lf = 0;
bool vis[1<<(20)+1];
vector<int> gens[1<<(4*5)+1];

int ng(int bs){
    bool td[N+2][M+2];
    string res;
    for(int i = 0;i< N+2; i++){
        td[i][0] = 0;
        td[i][M+1] = 0;
    }
    for(int i = 0;i< M+2; i++){
        td[0][i] = 0;
        td[N+1][i] = 0;
    }
    for(int i = 0; i < N*M; i++){
        td[i/M+1][i%M+1] = bs & (1<<(N*M-1-i));
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            int neighbours = 0;
            neighbours += td[i-1][j]+td[i+1][j]+td[i-1][j-1]+td[i+1][j+1]+td[i-1][j+1]+td[i+1][j-1]+td[i][j-1]+td[i][j+1];
            if(td[i][j]){
                if(neighbours < a || neighbours > b)res.push_back('0');
                else res.push_back('0'+td[i][j]);
            }
            else if(neighbours > c)res.push_back('1');
            else res.push_back('0'+td[i][j]);
        }
    }
    bitset<20> r(res);
    return r.to_ulong();
}

void bfs(int life){
    list<pii> q;
    q.emplace_back(life, 0);
    vis[life] = true;
    while(!q.empty()){
        pii c = q.front();
        q.pop_front();
        if(gens[c.first].empty()){
            printf("%d", c.second);
            return;
        }
        for(int x:gens[c.first]){
            if(vis[x])continue;
            q.emplace_back(x, c.second+1);
            vis[x] = true;
        }
    }
    printf("-1");
}

int main(){
    scanf("%d%d%d%d%d", &N, &M, &a, &b, &c);
    memset(vis, false, sizeof(vis));
    for(int i = 0;i < N; i++){
        char cur[M+5];
        scanf("%s", &cur);
        for (int j = 0; j < M; j++)
        {
            lf <<= 1;
            lf += cur[j]=='*'?1:0;
        }
    }
    for(int i = 0; i < 1<<(N*M); i++){
        gens[ng(i)].push_back(i);
    }

    bfs(lf);
    return 0;
}
