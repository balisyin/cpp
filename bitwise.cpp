/* *
 * balisyin 20190212
 * bit about algorithm
 * */
//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

//BW1 get the number show 1time, others show 3times
int the1times(int arr[], int n){
    int onetime = 0;
    int twotime = 0;
    int tritime;
    for(int i = 0; i < n; ++i){
        twotime = (onetime & arr[i]) | twotime;
        onetime = onetime ^ arr[i];
        tritime = onetime & twotime;
        twotime = twotime & (~tritime);
        onetime = onetime & (~tritime);
    }
    return onetime;
}

///BW2 


///

int main(int arg, char* args[]){
    int arr[] = {7, 2, 9, 7, 7, 9, 9};
    cout << "1 times number is: " << the1times(arr, sizeof(arr)/sizeof(int)) << endl;
    getchar();
    return 0;
}
