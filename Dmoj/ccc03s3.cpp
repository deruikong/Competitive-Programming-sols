//
// Created by RayKo on 2020-03-03.
//

#include <bits/stdc++.h>
#define max 30
#define ll long long int
using namespace std;

char h[max][max];
bool vis[max][max] = {false};

//if u don't know bfs :sob:
int bfs(int r, int c){
    int cur = 0;
    list<vector<int>> q;
    q.push_back({r,c});
    if(vis[r][c]) return 0;
    vis[r][c] = true;

    while(!q.empty()){
        vector<int> x = q.front();
        q.pop_front();
        cur++;
        if (h[x[0]-1][x[1]] == '.' && !vis[x[0]-1][x[1]]){q.push_back({x[0]-1, x[1]});vis[x[0]-1][x[1]] = true;}
        if (h[x[0]][x[1]-1] == '.' && !vis[x[0]][x[1]-1]){q.push_back({x[0], x[1]-1});vis[x[0]][x[1]-1] = true;}
        if (h[x[0]][x[1]+1] == '.' && !vis[x[0]][x[1]+1]){q.push_back({x[0], x[1]+1});vis[x[0]][x[1]+1] = true;}
        if (h[x[0]+1][x[1]] == '.' && !vis[x[0]+1][x[1]]){q.push_back({x[0]+1, x[1]});vis[x[0]+1][x[1]] = true;}
    }

    return cur;
}

int main() {
    //init
    int rooms = 0, r, c, tot;
    vector<int> t;
    //input
    cin >> tot;
    cin >> r,
    cin >> c;
    for(int i = 0; i < r; i++)scanf("%s", &h[i]);
    //algo
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (h[i][j] == '.') t.push_back(bfs(i, j));
        }
    }
    //sort reversed
    sort(t.rbegin(), t.rend());
    //iterate through results
    for(int i : t){
        if(tot-i >= 0 && i != 0){
            tot -= i;
            rooms++;
        }
        else break;
    }
    if(rooms == 1)printf("%d room, %d square metre(s) left over", rooms, tot);
    else printf("%d rooms, %d square metre(s) left over", rooms, tot);
    return 0;
};
