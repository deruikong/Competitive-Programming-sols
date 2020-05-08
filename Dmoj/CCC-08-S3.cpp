#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
using namespace std;
int grid[23][23], r, c;
bool vis[23][23];
void bfs(){
    list<pair<pii, int>> q;
    q.emplace_back(make_pair(1,1), 1);
    vis[1][1] = true;
    while(!q.empty()){
        pii pos = q.front().first;
        int steps = q.front().second, val = grid[pos.first][pos.second];
        q.pop_front();
        if(val == -1)continue;
        if(pos.first == r && pos.second == c){printf("%d\n", steps);return;}
        steps++;
        REP(i, 0, 3){
            int rr = 0, cc = 0;
            switch(i){
                case 0:rr++;break;
                case 1:rr--;break;
                case 2:cc++;break;
                case 3:cc--;break;
            }
            if(rr && val == 0)continue;
            if(cc && val == 1)continue;
            else if(!vis[pos.first+rr][pos.second+cc]){
                q.emplace_back(make_pair(pos.first+rr, pos.second+cc), steps);
                vis[pos.first+rr][pos.second+cc] = true;
            }
        }
    }
    printf("-1\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &r, &c);
        memset(grid, -1, sizeof(grid));
        memset(vis, false, sizeof(vis));
        REP(i, 1, r){
            string cur;
            cin >> cur;
            REP(j, 0, c-1){
                if(cur[j]=='+')grid[i][j+1] = 2;
                else if(cur[j] == '-')grid[i][j+1] = 0;
                else if(cur[j] == '|')grid[i][j+1] = 1;
                else grid[i][j+1] = -1;
            }
        }
        bfs();
    }
    return 0;
}