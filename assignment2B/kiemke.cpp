#include <bits/stdc++.h>
using namespace std;

int main() {
//     before banned "set"
//     int n; cin >> n;
//     set<int> s;
//     for(int i = 0; i < n; i++) {
//         int x; cin >> x;
//         s.insert(x);
//     }
//     cout << s.size();
    
//  after
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 0) return 0;
    vector<string> goods(n);
    
    for(int i = 0; i < n; i++) cin >> goods[i];

    // Sorting input
    qs_str(goods, 0, n - 1);
    // create answer vector
    vector<pair<string, int>> goods2;

    // pushing first element - <string, int>
    goods2.push_back({goods[0], 1});

    // if adding existed string, then update their cnt
    // else add <string, 1> to ans
    for (int i = 1; i < goods.size(); i++) {
        if (goods[i] == goods2.back().first)
            goods2.back().second++;
        else 
            goods2.push_back({goods[i], 1});
    }
    cout << goods2.size() << "\n";
    
}
