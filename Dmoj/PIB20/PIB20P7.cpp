//
// Created by RayKo on 2020-03-14.
//

#include <bits/stdc++.h>
#define maxn 5*10001
#define ll long long int
using namespace std;
int N;
vector<int> arr(maxn);

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)scanf("%d", &arr[i]);
    sort(arr.begin(), arr.begin()+N);
    for(int i = 0; i < N; i++)printf("%d ", arr[i]);
    return 0;
};
