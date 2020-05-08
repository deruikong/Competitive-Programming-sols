#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 0x3f3f3f
int N, K, arr[maxn];

int minS(int idx)
{
    if(idx == K)return 0;
    if(idx > K || arr[idx] == 0)return INF;
    int mins = INF;
    for(int i = idx+1; i < idx+arr[idx]; i++){
        mins = min(mins, minS(i)+1);
    }
    return mins;
}
int main() {
    scanf("%d%d", &N, &K);
    K--;
    arr[0] = 0;
    for(int i = 1; i < N+1; i++)scanf("%d", &arr[i]);
    int cur = minS(1);
    cout << (cur == INF?-1:cur) << endl;
    return 0;
};
