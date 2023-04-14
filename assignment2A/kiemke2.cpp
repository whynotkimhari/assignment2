#include <bits/stdc++.h>
using namespace std;

// Sorting input string
void qs_str(vector<string>& array, int l, int r);
int par_str(vector<string>& array, int Left, int Right);

// Sorting pair of string by its cnt
void QuickSort_cnt(vector<pair<string, int>>& array, int l, int r);
int Partition_cnt(vector<pair<string, int>>& array, int Left, int Right);

// Sorting pair of string by its string
void QuickSort_str(vector<pair<string, int>>& array, int l, int r);
int Partition_str(vector<pair<string, int>>& array, int Left, int Right);

int main() {
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

    // Sorting ans by DESC cnt
    // then by ASC string
    QuickSort_cnt(goods2, 0, goods2.size() - 1);
    QuickSort_str(goods2, 0, goods2.size() - 1);

    // cout
    for(auto it = goods2.begin(); it != goods2.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void QuickSort_cnt(vector<pair<string, int>>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_cnt(array, l, r);
    QuickSort_cnt(array, l, p);
    QuickSort_cnt(array, p + 1, r);
}

int Partition_cnt(vector<pair<string, int>>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    int pivot = array[index].second;
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].second > pivot);

        do{
            --j;
        }while(array[j].second < pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void QuickSort_str(vector<pair<string, int>>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_str(array, l, r);
    QuickSort_str(array, l, p);
    QuickSort_str(array, p + 1, r);
}

int Partition_str(vector<pair<string, int>>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    string pivot = array[index].first;
    int pivot_cnt = array[index].second;
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].second != pivot_cnt
            || (array[i].second == pivot_cnt && array[i].first.size() < pivot.size())
            ||(array[i].second == pivot_cnt && array[i].first.size() == pivot.size() && array[i].first < pivot));

        do{
            --j;
        }while(array[j].second != pivot_cnt
            || (array[j].second == pivot_cnt && array[j].first.size() > pivot.size())
            ||(array[j].second == pivot_cnt && array[j].first.size() == pivot.size() && array[j].first > pivot));

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void qs_str(vector<string>& array, int l, int r) {
    if(l >= r) return;
    int p = par_str(array, l, r);
    qs_str(array, l, p);
    qs_str(array, p + 1, r);
}

int par_str(vector<string>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    string pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].size() < pivot.size()
        || (array[i].size() == pivot.size() && array[i] < pivot));

        do{
            --j;
        }while(array[j].size() > pivot.size()
        || (array[j].size() == pivot.size() && array[j] > pivot));

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}