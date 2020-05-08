#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<unsigned char, unsigned char>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
int M, N;
unsigned char mat[103][104];
bool vis[103][103];

bool check(int a, int b, int x, int y, int z){
    unsigned char val = mat[a][b];
    if(a == 5 && b == 7){
        cout << "";
    }
    if(val == x || val == y || val ==z){
        return true;
    }
    return false;
}

bool bfs(int c, int x, int y, int z){
    list<pii> q;
    q.emplace_back(1, c);
    vis[1][c] = true;
    while(!q.empty()){
        pii cur = q.front();
        if(cur.first == M)
            return true;
        q.pop_front();
        for(int i = 0; i < 4; i++){
            int cr = 0, cc = 0;
            switch(i){
                case 0: cr++;break;
                case 1: cr--;break;
                case 2: cc++; break;
                case 3: cc--; break;
            };
            if(!vis[cur.first + cr][cur.second + cc] && check(cur.first + cr, cur.second + cc, x,y,z)){
                q.emplace_back(cur.first+cr, cur.second + cc);
                vis[cur.first+cr][cur.second+cc] = true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &N, &M);
    memset(mat, 254, sizeof(mat));
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%hhu", &mat[i][j]);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++, memset(vis, false, sizeof(vis)))
            {
                for(int l = 1; l <= N; l++){
                    if((mat[1][l] == i || mat[1][l] == j || mat[1][l] == k) && bfs(l, i, j, k)){
                        printf("%d %d %d", i, j, k);
                        return 0;
                    }
                }
            }
            
        }
    }
    printf("-1 -1 -1");
    return 0;
}