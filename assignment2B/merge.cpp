#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int *a, int n, int *b, int m, int *c) {
    int x = 0, y = 0, idc = 0;
    while(x < n && y < m) {
        if(a[x] <= b[y]) {
            c[idc] = a[x];
            x++;
            idc++;
        }
        else {
            c[idc] = b[y];
            y++;
            idc++;
        }
    }
    while(x < n) {
        c[idc] = a[x];
        x++;
        idc++;
    }
    while(y < m) {
        c[idc] = b[y];
        y++;
        idc++;
    }
}


int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
