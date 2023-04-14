#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int>& array, int l, int r);
int Partition(vector<int>& array, int Left, int Right);

int main() {
    ios::sync_with_stdio(false);
    int n, k; scanf("%d%d", &n, &k);
    vector<int> flowers;
    vector<bool> mark(n, false);
    flowers.reserve(n);
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        flowers.push_back(x);
    }
    QuickSort(flowers, 0, n - 1);
    int used = -1, count = 0;
    for(int i = 0; i < n; i++) {
        if(flowers[i] != used && mark[i] == false) {
            mark[i] = true;
            used = flowers[i];
            cout << flowers[i] << " ";
            count++;
            if(count == k) return 0;
        }
    }
    if(count < k) {
        for(int i = 0; i < n; i++) {
            if(mark[i] == false) {
                cout << flowers[i] << " ";
                count++;
                if(count == k) return 0;
            }
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