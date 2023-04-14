#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int>& array, int l, int r);
int Partition(vector<int>& array, int Left, int Right);

int main() {
    ios::sync_with_stdio(false);
    int n; scanf("%d", &n);
    map<int, vector<int>> oxy;
    vector<int> first;
    first.reserve(n);
    for(int i = 0; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        first.push_back(a);
        oxy[a].push_back(b);
    }
    int used = 0;
    QuickSort(first, 0, n - 1);
    for(auto x: first) {
        if(used != x) {
            QuickSort(oxy[x], 0, oxy[x].size() - 1);
            for(int i = oxy[x].size() - 1; i >= 0; i--) {
                cout << x << " " << oxy[x][i] << '\n';
            }
            used = x;
        }
    }
}

void QuickSort(vector<int>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition(array, l, r);
    QuickSort(array, l, p);
    QuickSort(array, p + 1, r);
}

int Partition(vector<int>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    int pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i] < pivot);

        do{
            --j;
        }while(array[j] > pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}