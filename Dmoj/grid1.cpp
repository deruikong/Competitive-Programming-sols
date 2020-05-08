#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;
ll grid[1000][1001];
const ll mod = 1e9+7;

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        char cur[b];
        scanf("%s", &cur);
        for (int j = 0; j < b; j++)
        {
            if(cur[j] == '#')grid[i][j] = -1;
            else grid[i][j] = 0;   
        }
    }
    for (int i = 0; i < a; i++)
    {
        if(grid[i][0] == -1)break;
        grid[i][0] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        if(grid[0][i] == -1)break;
        grid[0][i] = 1;
    }
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            if(grid[i][j] == -1)continue;
            grid[i][j] = (max(grid[i-1][j], 0LL)+max(grid[i][j-1], 0LL))%mod;
        }
    }
    printf("%lld", grid[a-1][b-1]);
    return 0;
}