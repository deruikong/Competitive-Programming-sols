//
// Created by RayKo on 2020-03-12.
//

#include <bits/stdc++.h>

#define ll long long int
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("move disk from %c to %c", A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    printf("move disk from %c to %c", A, C);
    hanoi(n - 1, B, A, C);
    return;
}

int main() {
    int a;
    scanf("%d", &a);
    hanoi(a, 'A', 'B', 'C');
    return 0;
};
