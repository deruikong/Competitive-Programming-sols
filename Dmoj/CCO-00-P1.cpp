//
// Created by RayKo on 2020-03-15.
//

#include <bits/stdc++.h>

#define ll long long int

using namespace std;
map<char, vector<char>> sets;
vector<bool> vis(26, false);

set<char> s(char a){
    if(vis[a-'A'])return {};
    vis[a-'A'] = true;
    if(sets[a].empty())return {};
    set<char> ret;
    for(char i: sets[a]){
        if(i-'a' >= 0)ret.insert(i);
        else{
            set<char> cur = s(i);
            ret.insert(cur.begin(), cur.end());
        }

    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        char p, c;
        string a;
        cin >> p >> a >> c;
        sets[p].push_back(c);
    }
    for(auto& x: sets){
        string out;
        set<char> cur = s(x.first);
        for(auto& a: cur){
            out.push_back(a);
            out+=",";
        }
        if(!out.empty())out.pop_back();
        cout << x.first << " = {" << out << "}\n";
        fill(vis.begin(), vis.end(), false);
    }
    return 0;
};
