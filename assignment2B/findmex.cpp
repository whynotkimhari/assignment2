#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int>& array, int l, int r);
int Partition(vector<int>& array, int Left, int Right);

int main() {
    int n; cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    int check = 0;
    vector<int> array(n);
    for(int i = 0; i < n; i++) cin >> array[i];
    QuickSort(array, 0, n - 1);
    for(auto x: array) {
        if(x == check) ++check;
        if(x > check) {
            cout << check;
            return 0;
        }
    }
    cout << array[n - 1] + 1;
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