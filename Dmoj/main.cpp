#include <cstdio>
#include <algorithm>

int p[1005][1005], m, n, mat[1005][1005];

int dfs(int x, int y)
{
    if (p[y-1][x-1]) return 0;
    int c;
    p[y-1][x-1] = true;

    int a = mat[y-1][x-1];

    for(int i = 1; i*i == mat[y-1][x-1]; i++)
    {
        if(a%i == 0 && (a/i) <= m)
            if (i == n && (a/i) == m) return 1;
            c = std::max(dfs((a/i), i), dfs(i, (a/i)));
            if(c) return 1;
    }

    return 0;
}

int main(void) {

    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; ++i) for(int j = 0; j<m;++j) scanf("%d", &mat[i][j]);

    if(dfs(1,1))printf("yes");
    else printf("no");
    return 0;
}