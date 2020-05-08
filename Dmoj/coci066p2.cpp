//
// Created by RayKo on 2020-02-29.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, a, b;
    cin >> r >> c;
    char pat[r*2][c*2+5];
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char cur;
            cin >> cur;
            pat[i][j] = cur;
            pat[i + 2 *(r-i) - 1][j + 2 * (c-j) - 1] = pat[i + 2 * (r-i) - 1][j] = pat[i][j + 2 * (c-j) - 1] = pat[i][j];
        }
    }
    cin >> a >> b;
    if(pat[a-1][b-1] == '#')pat[a-1][b-1] = '.';
    else pat[a-1][b-1] = '#';
    for(int i = 0; i<r*2;i++)
    {
        for (int j = 0; j < c*2; j++)cout << pat[i][j];
        cout << endl;
    }
    return 0;
};
