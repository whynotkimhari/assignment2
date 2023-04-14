#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<pair<int, int>>& array, int l, int r);
int Partition(vector<pair<int, int>>& array, int Left, int Right);
void QuickSort_(vector<pair<int, int>>& array, int l, int r);
int Partition_(vector<pair<int, int>>& array, int Left, int Right);
pair<int, int> search(vector<pair<int, int>>& array, int x);

int main() {
    unsigned int n, q;
    cin >> n >> q;
    vector<pair<int, int>> arr;
    arr.reserve(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(make_pair(x, i + 1));
    }
    QuickSort(arr, 0, n - 1);
    QuickSort_(arr, 0, n - 1);
    // for(auto x: arr) cout << x.first << " " << x.second << endl;

    string s;
    int x, y;
    while(q > 0) {
        cin >> s >> x >> y;
        // id1 is index in zorted arr
        // id2 is index in plain arr
        int id1 = search(arr, y).first, id2 = search(arr, y).second;
        if(id1 == -1 && id2 == -1) cout << - 1 << endl;
        else {
            if(x == 1) {
                for(int i = 0; i < id1; i++) if(arr[id1].first == arr[i].first) {
                    id2 = arr[i].second;
                    break;
                }
            }
            else {
                for(int i = n - 1; i > id1; --i) if(arr[id1].first == arr[i].first) {
                    id2 = arr[i].second;
                    break;
                }
            }
            cout << id2 << endl;
        }
        --q;
    }
}

void QuickSort(vector<pair<int, int>>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition(array, l, r);
    QuickSort(array, l, p);
    QuickSort(array, p + 1, r);
}

int Partition(vector<pair<int, int>>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    int pivot = array[index].first;
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].first < pivot);

        do{
            --j;
        }while(array[j].first > pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void QuickSort_(vector<pair<int, int>>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_(array, l, r);
    QuickSort_(array, l, p);
    QuickSort_(array, p + 1, r);
}

int Partition_(vector<pair<int, int>>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    pair<int, int> pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].first != pivot.first
        || (array[i].first == pivot.first && array[i].second < pivot.second));

        do{
            --j;
        }while(array[j].first != pivot.first
        || (array[j].first == pivot.first && array[j].second > pivot.second));

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

pair<int, int> search(vector<pair<int, int>> &array, int x) {
    int left = 0, right = array.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(x == array[mid].first) return make_pair(mid, array[mid].second);
        else if(x < array[mid].first) right = mid - 1;
        else left = mid + 1;
    }
    return make_pair(-1, -1);
}