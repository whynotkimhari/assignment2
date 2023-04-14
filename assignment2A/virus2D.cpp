#include <bits/stdc++.h>
using namespace std;

void all_sub(unordered_map<string, int> &sub, string s) {
    for(int i = 0; i < s.size(); i++) for(int j = 2; j < 11; j++) sub[s.substr(i, j)] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<string> rec1D;
    rec1D.reserve(n);
    unordered_map<string, int> sub;


    // time comp: O(n*m*10)
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        rec1D.push_back(s);
        all_sub(sub, s);
    }

    // time comp: O(m*n + m*m*10)
    // for(int i = 0; i < m; i++) {
    //     string s = "";
    //     for(int j = 0; j < n; j++) s = s + rec1D[j][i];
    //     // rec1D.push_back(s);
    //     all_sub(sub, s);
    // }

    for(int i = 0; i < m; i++) {
        stringstream ss;
        for(const auto& s : rec1D) {
            ss << s[i];
        }
        string s = ss.str();
        all_sub(sub, s);
    }

    // time comp: O(q)    
    while(q--) {
        string virus; cin >> virus;
        cout << sub[virus];
    }
}
