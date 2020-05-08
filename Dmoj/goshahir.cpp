//
// Created by RayKo on 2020-02-29.
//

#include <bits/stdc++.h>
using namespace std;

struct road{
    int a, b;
    bool operator<(const road& rhs) const{
        return tie(a, b) < tie(rhs.a, rhs.b) || tie(b, a) < tie(rhs.a, rhs.b);
    }
};

set<road> r;

bool bfs(int a, int c, int t)
{
    list<int> q;
    vector<bool> unvisited(t, true);
    unvisited[a-1] = false;
    q.push_back(a);
    while(!q.empty()){
        a = q.front();
        q.pop_front();
        for(auto& cur: r)
        {
            if((cur.a == a || cur.b == a) && (cur.a == c || cur.b == c))return true;
            if(cur.a == a && unvisited[cur.b-1])
            {
                unvisited[cur.b-1] = false;
                q.push_back(cur.b);
            }
            else if(cur.b == a && unvisited[cur.a-1]){
                unvisited[cur.a-1] = false;
                q.push_back(cur.a);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i = 0; i< m; i++){
        road cur;
        cin >> cur.a >> cur.b;
        r.insert(cur);
    }
    if(bfs(a, b, n))cout << "GO SHAHIR!";
    else cout << "NO SHAHIR!";
    return 0;
};
