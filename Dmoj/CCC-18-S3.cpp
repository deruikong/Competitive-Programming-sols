//
// Created by RayKo on 2020-03-11.
//

#ifdef ray
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
#define INF 1e4+5
#define ll long long int
#define pii pair<int,int>
using namespace std;

int N, M;
pair<int, int> S;
vector<pii> T;
char r[105][105];
int vis[105][105];
string check = "LRUD";

bool endp(pii& origin){
    pii t = origin;
    while(true)
    {
        switch (r[t.first][t.second])
        {
            case 'U': t.first--;break;
            case 'D': t.first++;break;
            case 'L': t.second--;break;
            case 'R': t.second++;break;
            default:return false;
        }
        if (r[t.first][t.second] == '.')
        {
            if (vis[t.first][t.second] >= 0) return false;
            else { origin = t; return true; }
        }
        else if (vis[t.first][t.second] < 0)vis[t.first][t.second] = 0;
        else return false;
    }
}

pair<int, int> w(pii a, int d){
    switch (d)
    {
        case 0: return make_pair(--a.first, a.second);
        case 1: return make_pair(++a.first, a.second);
        case 2: return make_pair(a.first, --a.second);
        case 3: return make_pair(a.first, ++a.second);
        default:break;
    }
}

void bfs(){
    string m = "LRUD";
    list<pii> q;
    q.push_back(S);
    if(vis[S.first][S.second] == 0) return;
    vis[S.first][S.second] = 0;

    while(!q.empty()){
        pii cur = q.front();
        q.pop_front();
        for(int i = 0; i < 4; i++){
            pii tar = w(cur, i);
            if(r[tar.first][tar.second] != 'W'){
                if(r[tar.first][tar.second] == '.'){
                    if(vis[tar.first][tar.second] < 0){vis[tar.first][tar.second] = vis[cur.first][cur.second] + 1;q.push_back(tar);}
                }
                else if(endp(tar)){vis[tar.first][tar.second] = vis[cur.first][cur.second]+1;q.push_back(tar);}
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    vector<pii> c;
    for(int i = 0; i < N; i++)memset(vis[i], -1, sizeof(vis[0][0]) * M);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", &r[i]);
        for(int j = 0; j < M; j++){
            if(r[i][j] == 'S')S = make_pair(i, j);
            else if(r[i][j] == '.')T.emplace_back(i,j);
            else if(r[i][j] == 'C')c.emplace_back(i, j);
        }
    }
// precompute camera
    for(auto& x: c){
        auto a = x;
        vis[x.first][x.second] = true;
        while(r[x.first][x.second]!='W'){
            if(r[x.first][x.second] == '.' || r[x.first][x.second] == 'S') vis[x.first][x.second] = 0;
            x.first--;
        }
        x.first = a.first;
        while(r[x.first][x.second]!='W'){
            if(r[x.first][x.second] == '.' || r[x.first][x.second] == 'S') vis[x.first][x.second] = 0;
            x.first++;
        }
        x.first = a.first;
        while(r[x.first][x.second]!='W'){
            if(r[x.first][x.second] == '.' || r[x.first][x.second] == 'S') vis[x.first][x.second] = 0;
            x.second--;
        }
        x.second = a.second;
        while(r[x.first][x.second]!='W'){
            if(r[x.first][x.second] == '.' || r[x.first][x.second] == 'S') vis[x.first][x.second] = 0;
            x.second++;
        }
    }
    bfs();
    //print result
    for(auto& x: T){
        auto cur =  vis[x.first][x.second];
        if(cur != 0) printf("%d\n", cur);
        else printf("-1\n");
    }
    return 0;
};