#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
using namespace std;
map<int, int> a;
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){int cur; scanf("%d", &cur); a[cur]++;}
    if(a.size() < 3)printf("Slavko\n%d %d", a.begin()->first, a.rbegin()->first);
    else {
        while (a.size() > 2) {
            int t = min(a.begin()->second, a.rbegin()->second);
            a[a.begin()->first] -= t;
            a[a.rbegin()->first] -= t;
            a[next(a.begin())->first] += t;
            a[prev(a.end(), 2)->first] += t;
            if(a[a.rbegin()->first] == 0)a.erase(prev(a.end()));
            if(a[a.begin()->first] == 0)a.erase(a.begin());
        }
        if (a.begin()->second <= a.rbegin()->second) {
            printf("Slavko\n%d %d", a.begin()->first, a.rbegin()->first);
        }
        else printf("Mirko\n%d %d", a.begin()->first, a.rbegin()->first);
    }
    return 0;
};