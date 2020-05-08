#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr(10, 0);
    iota(begin(arr), end(arr), 1);
    int N = arr.size();
    int a = 1 << N;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < N; j++)
            if((i >> j) & 1) cout << arr[j] << ' ';
    cout << '\n';
}