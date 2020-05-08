#include <bits/stdc++.h>
using namespace std;
double K, D[100000];
int N;
bool good(double t) {
    double prev = D[0] + t;
    for (int i = 1; i < N; i++) {
        if (D[i] - t > prev + K) {
            return false;
        } else {
            prev = min(D[i] + t, prev + K);
        }
    }
    return true;
}
int main() {
    cin >> K >> N;
    for (int i = 0; i < N; i++) cin >> D[i];
    double lo = 0, hi = 1000000000;
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (good(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.4f\n",lo);

    return 0;
}
