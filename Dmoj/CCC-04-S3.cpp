//
// Created by RayKo on 2020-03-19.
// first tried hype

#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
using namespace std;
const int MAXN = 40;
vector<pii> val;

string a[10][15];
int f[10][10];
bool vis[10][10];

int getval(int i, int j){
    if(vis[i][j] || f[i][j] != -1)return f[i][j];
    vis[i][j] = true;
    stringstream cur(a[i][j]);
    int ret = 0;
    string spl;
    while(getline(cur, spl, '+')){
        int cur = getval(spl[0]-'A', spl[1]-'1');
        if(cur == -1){ret = -1;break;}
        ret+=cur;
    }
    f[i][j] = ret;
    return ret;
}

int main() {
    for(int i = 0; i < 10; i++)for(int j = 0; j < 9; j++){cin >> a[i][j]; f[i][j] = a[i][j][0]-'1' < 10?stoi(a[i][j]):-1; if(f[i][j]==-1)val.emplace_back(i, j);}
    for(auto& x:val){
        memset(vis, false, 10*9*sizeof(vis[0][0]));
        getval(x.first, x.second);
    }
    for(int i = 0; i < 10; i++){for(int j = 0; j < 9; j++)f[i][j]==-1?cout << "* ":cout << f[i][j] << ' ';cout << '\n';}
    return 0;
};
