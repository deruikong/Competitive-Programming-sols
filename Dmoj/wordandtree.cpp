#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

char val[(int)1e5 + 5];
vector<int> adj[(int)1e5 + 1];
int cnt[(int)1e5 + 1][26];
vector<bool> vis((int)1e5 + 1, false);

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
            for(int i = 0; i < 26; i++){
                cnt[u][i] += cnt[v][i];
            }
        }
    }
    cnt[u][val[u] - 'a']++;
}

int main(){
    scanf("%d%d\n", &n, &k);
    for(int i = 0; i < n; i++){
        char cur;
        scanf("%c ", &cur);
        val[i] = cur;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    while(k--){
        int a, l, tot = 0; char cur[(int)1e6 + 5];vector<int> ccnt(27, 0);
        scanf("%d%s", &a, cur);
        a--;
        l = strlen(cur);
        for(int i = 0; i < l; i++){
            ccnt[cur[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            tot += max(0, ccnt[i] - cnt[a][i]);
        }
        printf("%d\n", tot);
    }
}
