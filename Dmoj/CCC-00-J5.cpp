//
// Created by RayKo on 2020-03-03.
//

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

map<string, vector<string>> adj;
map<string, vector<bool>> vis;

bool dfs(string s1, const string& s2, int l){
    vis[s1][l] = true;
    if(s1 == s2) return true;
    bool ret = false;

    for(auto& x: adj[s1]){
        if(vis.find(x) != vis.end()){
            if(!vis[x][l])ret = max(ret,dfs(x, s2, l));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    vector<bool> f(a+5, false);
    for(int i = 0; i < a; i++){
        string html, cur;
        vector<string> links;
        cin >> html;
        vis[html] = f;
        do{
            getline(cin, cur);
            while(true) {
                size_t b = cur.find("<A HREF=\"");
                if (b != string::npos) {
                    cur.erase(0, b + 9);
                    size_t e = cur.find("\">");
                    string link = cur.substr(0, e);
                    cout << "Link from " << html << " to " << link << endl;
                    links.push_back(link);
                }
                else break;
            }
        }
        while(cur!="</HTML>");
        adj[html] = links;
    }
    int l = 0;
    while(true){
        string b1, b2;
        getline(cin, b1);
        if(b1 == "The End") break;
        getline(cin, b2);
        if(b2 == "The End") break;
        else{
            if(dfs(b1, b2, l))cout << "Can surf from " << b1 << " to " << b2 << "." << endl;
            else cout << "Can't surf from " << b1 << " to " << b2 << "." << endl;
        }
        l++;
    }
    return 0;
};
