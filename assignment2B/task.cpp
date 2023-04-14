#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int n, k, p, q;
    cin >> n >> k >> p >> q;

    // convert 2D to 1D index
    int alice = 2 * (p - 1) + q;

    // init
    int bob, bob_front = - 1, bob_back = - 1;

    // index if Bob can sit in front of Alice, else -1
    if(alice > k) bob_front = alice - k;

    // index if Bob can sit behind Alice, else -1
    if(alice + k < n + 1) bob_back = alice + k;

    // check where Bob is now, prefer "in front of" than "behind"
    if(bob_front != -1) bob = bob_front;
    if(bob_front == - 1 && bob_back != -1) bob = bob_back;
    if(bob_front == -1 && bob_back == -1) {
        cout << -1;
        return 0;
    }

    // convert 1D back to 2D index
    int u = -1, v = -1;
    if(bob % 2 == 1) v = 1;
    else v = 2;
    u = (bob - v + 2) / 2;

    // output
    if(u != - 1 && v != -1) cout << u << " " << v;
    else cout << - 1;
}