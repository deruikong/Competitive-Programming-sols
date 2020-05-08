#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
using namespace std;

struct node{
    int par = 0;
    vector<int> child;
};

int main(){
    int L;
    scanf("%d", &L);
    for (int i = 0; i < L; i++)
    {
        int N, par = 0;
        map<int, node> tree;
        map<string, int> m;
        vector<string> r;
        int prev = -1, idx = 1;
        tree[0] = node{0, {1}};
        scanf("%d", &N);
        int old = N*10;
        for (int i = 0; i < N; i++)
        {
            string cur;
            cin >> cur;
            if(i==N-1)m[cur] = 0;
            else if(m.find(cur)==m.end()){
                m[cur] = idx++;
            }
            r.push_back(cur);
        }
        set<int> s;
        for(int i = 0; i< N; i++){
            string cur = r[i];
            if(prev == -1){
                tree[m[cur]] = node{0};
            }
            
            else{
                if(s.find(m[cur])!=s.end() && prev != 0){
                    tree[prev].par = m[cur];
                    tree[m[cur]].child.push_back(prev);
                }
            }
            prev = m[cur];
            s.insert(prev);
        }
        int xin = 0;
        list<pii> q;
        vector<bool> vis(2*N, false);
        q.emplace_back(0, 0);
        while(!q.empty()){
            pii cur = q.front();
            q.pop_front();
            if(cur.first == 0 && cur.second != 0)
            {
                xin = max(xin, cur.second);continue;
            }
            cur.second += 10;
            if(tree[cur.first].child.empty() || vis[cur.first]){q.emplace_back(tree[cur.first].par, cur.second);continue;}
            vis[cur.first] = true;
            for(int x: tree[cur.first].child){
                q.emplace_back(x, cur.second);
            }
        }
        cout << old-xin << endl;
    }
    
    return 0;
}