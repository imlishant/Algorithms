#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(vector<int> arr, int low, int high){
    for(int i = low; i <= high; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int j = low;

    for (int i = low+1; i <= high; i++) {
        if (arr[i] < pivot) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[low], arr[j]);
    return j;  
}

/*
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int j = high;

    for (int i = high; i > low; i--) {
        if (arr[i] > pivot) {
            swap(arr[j--], arr[i]);
        }
    }
    swap(arr[low], arr[j]);
    return j;  
}
*/

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n-1); 
    printArray(arr, 0, n-1);
    return 0;
}
