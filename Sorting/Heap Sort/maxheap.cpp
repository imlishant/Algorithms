#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int>& arr, int i, int size){
    int l = 2*i+1;
    int r = 2*i+2;
    int max = i;
    if(l < size && arr[l] > arr[max])
        max = l;
    if(r < size && arr[r] > arr[max])
        max = r;
    if(max != i){
        swap(arr[i], arr[max]);
        max_heapify(arr, max, size);
    }
}

void build_maxheap(vector<int>& arr, int size){
    for(int i = size/2; i>=0; i--)
        max_heapify(arr, i, size);
}

void heapsort(vector<int>& arr, int size){
    build_maxheap(arr, size);
    for(int i = size-1; i>0; i--){
        cout << arr[0] << " ";
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    heapsort(arr, n);
    /*
    for(int i = n-1; i>=0; i--){
        cout << arr[i] << " ";
    }
    */
    
    return 0;
}
