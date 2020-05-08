#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int r, c, N;
int grid[53][53];
bool vis[53][53];

void bfs(int ir, int ic){
    int tot = INT_MAX;
    list<pair<pii, int>> q;
    q.emplace_back(make_pair(ir, ic), 0);
    vis[ir][ic] = true;
    while(!q.empty()){
        pair<pii, int> cur = q.front();
        int r = cur.fi.fi, c = cur.fi.se;
        q.pop_front();
        int val = grid[cur.fi.fi][cur.fi.se];
        if(val == 1){tot = cur.second;break;}
        else if(val == -1)continue;
        if(cur.second == 59)continue;
        REP(i, 1, 4){
            int rr = 0, cc = 0;
            switch(i){
                case 1:rr++;break;
                case 2:rr--;break;
                case 3:cc++;break;
                case 4:cc--;break;
            }
            if(!vis[r+rr][c+cc])q.emplace_back(make_pair(r+rr, c+cc), cur.se+1),vis[r+rr][c+cc] = true;
        }
    }
    if(tot >= 60)printf("#notworth\n");
    else printf("%d\n", tot);
}

int main(){
    scanf("%d", &N);
    while(N--){
        int ir, ic;
        scanf("%d%d", &c, &r);
        memset(grid, -1, sizeof(grid));
        memset(vis, false, sizeof(vis));
        REP(i, 1, r){
            string str;
            cin >> str;
            REP(j, 0, c-1){
                if(str[j] == 'C')ir = i, ic = j+1, grid[i][j+1] = 0;
                else if(str[j] == 'X')grid[i][j+1] = -1;
                else if(str[j] == 'W')grid[i][j+1] = 1;
                else grid[i][j+1] = 0;
            }
        }
        bfs(ir, ic);
    }
    return 0;
}