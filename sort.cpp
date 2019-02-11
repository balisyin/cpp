/* *
 * balisyin 20190209
 * all sort algorithm
 * */
#include<bits/stdc++.h>
using namespace std;
#define LEN 50000
void swap(int& m, int& n){int tmp = m; m = n; n = tmp;}

///QUICK SORT
int partition(int arr[], int l, int r){
    int part = arr[r];
    int j = l - 1;
    for(int i = l; i < r; ++i){
        if(arr[i] < part){
            ++j;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[r]);
    return j+1;
}
void quickSort(int arr[], int l, int r){
    int mid = partition(arr, l, r);
    if(mid - 1 > l)
        quickSort(arr, l, mid - 1);
    if(mid < r - 1)
        quickSort(arr, mid+1, r);
    return;
}

///MERGE SORT
void mergeSort(int arr[], int l, int r){
    int tmp[r-l];
    int mid = (r-l) > 1;
    if(mid > l){
        mergeSort(arr, l, mid);
    }
    if((mid+1) < r){
        mergeSort(arr, mid+1, r);
    }
    int i = l;
    int j = r;
    int k = 0;

    while(i<l && j<r){
        if(arr[i] < arr[j]){
            tmp[k++] = arr[i++];
        } else{
            tmp[k++] = arr[j++];
        }
    }
    while(i < l){
        tmp[k++] = arr[i++];
    }
    while(j < r){
        tmp[k++] = arr[j++];
    }

    for(int index = 0; index < k; ++index){
        arr[l+index] = tmp[index];
    }

    return;
}

///HEAP SORT
void heapAdjust(int arr[], int n){
    i = 0;
    while(i < n){
        int kidL = i<<1 + 1;
        int kidR = kidL + 1;
        int smaller = i;
        if(kidL < n && arr[kidL] < arr[smaller]){
            smaller = kidL;
        }
        if(kidR < n && arr[kidR] < arr[smaller]){
            smaller = kidR;
        }
        if(smaller != i){
            swap(arr[i], arr[smaller]);
            i = smaller;
        }
    }

    return;
}

void heapSort(int arr[], int n) {
    for(int i = 0; i < (n >> 1); ++i)
        heapAdjust(&arr[i], n)

    for(int j = n -1; j > 1; --j){
        swap(arr[0], arr[j]);
        heapAdjust(arr, j-1);
    }
    return;
}


///SELECT SORT


／*************main****************／
int main(int arg, char* args[]) {

    //int* arr = new int[LEN];
    int arr[LEN];
    for(int i = 0; i < LEN; ++i)
        arr[i] = LEN - i;
    auto begin = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);
    quickSort(arr, 0, LEN-1);
    auto end = chrono::system_clock::now().time_since_epoch() / chrono::seconds(1);
    cout << "sort " << LEN << " numbers use " << end - begin << " ms" << endl;

    for(int j = 0; j < LEN; ++j)
        //cout << arr[j] << endl;

    return 0;
}

