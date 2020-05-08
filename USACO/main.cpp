/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

#include <bits/stdc++.h>
using namespace std;
int N, M, happy = 0;
vector<int> parent(100002, -1);
vector<int> adj[100002];
vector<bool> vis(100002, 0);

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            parent[i] = i;
            dfs(i);
        }
    }
    for(int i = 1; i <= N; i++){
        if(parent[i] == i)continue;
        int parChild = adj[parent[i]].size();
        if(parent[parent[i]] != parent[i])parChild--;
        if(adj[i].size()-1 > parChild)happy++;
    }
    printf("%d", happy);
    return 0;
}