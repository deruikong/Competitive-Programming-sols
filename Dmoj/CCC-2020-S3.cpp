#include <bits/stdc++.h>
using namespace std;
#define d 26

int main() {
    string n, h, curr;
    int nl, hl, total = 0;
    const int arrLen = 26;
    int mask[arrLen] = {0}, currV[arrLen] = {0}, t = 0, q = 31, h1 = 1;
    unordered_set<int> perms;
    scanf("")
    cin >> h;
    nl = n.length();
    hl = h.length();
    if (nl <= hl) {
        int j;
        for (int i = 0; i < nl - 1; i++)
            h1 = (h1 * d) % q;
        for (int i = 0; i < nl; i++) {
            t = (d * t + h.c_str()[i]) % q;
            mask[n[i] - 'a'] ++;
        }

        for (int i = 0; i < hl; i++) {
            if (i == 0) {
                for (j = 0; j < nl; ++j) currV[h.c_str()[i+j] - 'a'] ++;
            }
            else {
                currV[h.c_str()[i - 1] - 'a'] --;
                currV[h.c_str()[i+nl - 1] - 'a'] ++ ;
            }

            for (j = 0; j < arrLen; j++) {
                if (mask[j] != currV[j]) {
                    break;
                }
            }

            if (t < 0)
                t = (t + q);
            if (perms.find(t) == perms.end()) {
                if (j == arrLen) {
                    total++;
                }
            }

            if (i + nl >= hl) {
                break;
            }
            perms.insert(t);
            t = ((d*(t - h[i]*h1) + h[i+nl])%1000000007)%q;
        }
    }

    cout << total << endl;

    return 0;
}
