//
// Created by RayKo on 2020-03-13.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int a, tot = 0;

void add(int n, vector<int> path) {
    if(n==0 && path.back()!=a){
        tot++;
        printf("%d=", a);
        for(int i = 0; i < path.size(); i++){
            if(i != path.size()-1)printf("%d+", path[i]);
            else printf("%d\n", path[i]);
        }
    }
    int i;
    if(n == a) i = 1;
    else i = path.back();
    for (i; i <= n; i++) {
        path.push_back(i);
        add(n-i, path);
        path.pop_back();
    }
}

int main() {
    scanf("%d", &a);
    add(a, {});
    printf("total=%d", tot);
    return 0;
};
