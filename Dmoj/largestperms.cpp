//
// Created by RayKo on 2020-03-11.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    FILE * in;
    in = fopen("input.txt", "r");
    int arr[100005];
    int n, k;
    fscanf(in, "%d%d", &n, &k);
    for(int i = 0; i < n; i++)fscanf(in ,"%d", &arr[i]);
    map<int, int, greater<int>> pos;
    for(int i = 0; i < n; i++)pos[arr[i]] = i;
    for(int i = 0; i < n && k; i++){
        if(arr[i] == n-i) continue;
        int temp = pos.begin()->second;
        cout << pos.begin() -> first << endl;
        pos[arr[i]] = temp;
        swap(arr[temp], arr[i]);
        k--;
        pos.erase(pos.begin());
    }
    for(int j = 0; j< n; j++)printf("%d ", arr[j]);

    return 0;
};
