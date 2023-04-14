#include <bits/stdc++.h>
using namespace std;

struct Point3D {
    int x, y, z;
};

void QuickSort_x(vector<Point3D>& array, int l, int r);
int Partition_x(vector<Point3D>& array, int Left, int Right);
void QuickSort_y(vector<Point3D>& array, int l, int r);
int Partition_y(vector<Point3D>& array, int Left, int Right);
void QuickSort_z(vector<Point3D>& array, int l, int r);
int Partition_z(vector<Point3D>& array, int Left, int Right);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; scanf("%d", &n);
    vector<Point3D> oxy;
    oxy.reserve(n);
    for(int i = 0; i < n; i++) {
        Point3D a;
        scanf("%d%d%d", &a.x, &a.y, &a.z);
        oxy.push_back(a);
    }
    QuickSort_x(oxy, 0, n - 1);
    QuickSort_y(oxy, 0, n - 1);
    QuickSort_z(oxy, 0, n - 1);
    for(auto a: oxy) {
        cout << a.x << " " << a.y << " " << a.z << endl;
    }
}

void QuickSort_x(vector<Point3D>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_x(array, l, r);
    QuickSort_x(array, l, p);
    QuickSort_x(array, p + 1, r);
}

int Partition_x(vector<Point3D>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    int pivot = array[index].x;
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i].x < pivot);

        do{
            --j;
        }while(array[j].x > pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void QuickSort_y(vector<Point3D>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_y(array, l, r);
    QuickSort_y(array, l, p);
    QuickSort_y(array, p + 1, r);
}

int Partition_y(vector<Point3D>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    Point3D pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while((array[i].x == pivot.x && array[i].y > pivot.y) 
                || array[i].x != pivot.x
            );

        do{
            --j;
        }while((array[j].x == pivot.x && array[j].y < pivot.y) 
                || array[j].x != pivot.x
            );

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void QuickSort_z(vector<Point3D>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition_z(array, l, r);
    QuickSort_z(array, l, p);
    QuickSort_z(array, p + 1, r);
}

int Partition_z(vector<Point3D>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    Point3D pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while((array[i].x == pivot.x && array[i].y == pivot.y && array[i].z < pivot.z) 
                || (array[i].x == pivot.x && array[i].y != pivot.y)
                || array[i].x != pivot.x
            );

        do{
            --j;
        }while((array[j].x == pivot.x && array[j].y == pivot.y && array[j].z > pivot.z)
                || (array[j].x == pivot.x && array[j].y != pivot.y)
                || array[j].x != pivot.x
            );

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}