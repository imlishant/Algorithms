#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(vector<int>& arr, int low, int high){
    for(int i = low; i <= high; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(vector<int>& arr, int low, int high){
    int i = low;
    vector<int> left;
    vector<int> right;
    int pivot = arr[low];
    //assuming all numbers are different.
    for (int j = low+1; j <= high; j++) {
        if (arr[j] < pivot)
            left.push_back(arr[j]);
        else if (arr[j] > pivot)
            right.push_back(arr[j]);
    }
    for (int num : left)
        arr[i++] = num;
    arr[i++] = pivot;
    for (int num : right)
        arr[i++] = num;
    return low + left.size();
}

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
        printArray(arr, low , high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n-1); 
    return 0;
}
