#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    vector<int> line(n);

    for(int i = 0; i < n; i++) {
        line[i] = n - i; 
    }

    while(m--) {
        int x;
        cin >> x;

        line.push_back(x);
    }
    vector<int> check(n+1, 0);
    for (int i = line.size() - 1; i >= 0; i--) {
        if (check[line[i]]) continue;
        cout << line[i] << " ";
        check[line[i]] = 1;
    }

    // 5 4 3 2 1 5 4  4 5 4 
    // for(auto x: line) cout << x.first << " " << x.second << endl;
}