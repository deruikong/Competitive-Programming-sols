//
// Created by RayKo on 2020-03-01.
//

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const char alf[27] = "zyxwvutsrqponmlkjihgfedcba";
vector<string> all;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string tot;
    int t;
    cin >> t;
    while(t--){
        string cur;
        cin >> cur;
        all.push_back(cur);
    }
    vector<int> s(all.size());
    for(auto& let: alf){

        bool found = true;
        do {
            vector<int> pos(all.size());
            for(int j = 0; j < all.size(); j++){
                int curr = s.size() == all.size()?s[j]:0;
                size_t cp = all[j].find_first_of(let, curr);
                if(cp == string::npos)
                {
                    found = false;
                    break;
                }
                pos[j] = cp+1;
            }
            if(found){
                tot.push_back(let);
                s = pos;
            }
        }
        while(found);
    }
    if(tot.empty()) cout << -1 << endl;
    else cout << tot << endl;
    return 0;
};
