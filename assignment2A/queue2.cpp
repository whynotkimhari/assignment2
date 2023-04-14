#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> map1, map2;

    for(int i = 0; i < n + 1; i++) {
        map1[i + 1] = i;
        map2[i] = i + 1;
    }

    while(m--) {
        // 5 4 3 2 1
        int x; cin >> x; // 5
        int to_x = map2[x]; // 6
        int x_to = map1[x]; // 4

        map1[to_x] = x_to; // map1[6] = 4
        map2[x_to] = to_x; // map2[4] = 6

        map1[x] = 0; // map1[5] = 0
        
        int y = map2[0]; // y = 1
        map2[0] = x; // map2[0] = 5

        map1[y] = x; // map1[1] = 5
        map2[x] = y; // map2[5] = 1

        // cout << y << endl;
        // cout << map2[5] << endl;
        cout << map1[n + 1] << " ";
    }
}