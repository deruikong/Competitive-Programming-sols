#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, c = 2;
    cin >> a;
    string b;
    cin >> b;
    vector<int> f;
    if(a != 0) {
        f.push_back(1);
        f.push_back(1);
        while (true) {
            if (f[c - 1] + f[c - 2] <= a)f.push_back(f[c - 1] + f[c - 2]);
            else break;
            c++;
        }
        unordered_set<int> set(f.begin(), f.end());
        bool t = true;
        for(int i = 0; i < b.length(); i++){
            if((set.find(i+1) == set.end() && b[i]=='A') || (b[i] != 'A' && set.find(i+1) != set.end())){
                t = false;
                break;
            }
        }
        if (t)cout << "That's quite the observation!";
        else cout << "Bruno, GO TO SLEEP";
    }
    else  cout << "Bruno, GO TO SLEEP";
    return 0;
}