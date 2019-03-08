#include <bits/stdc++.h>
using namespace std;

void min_heapify(vector<int>& arr, int i, int size){
    int l = 2*i+1;
    int r = 2*i+2;
    int min = i;
    if(l < size && arr[l] < arr[min])
        min = l;
    if(r < size && arr[r] < arr[min])
        min = r;
    if(min != i){
        swap(arr[i], arr[min]);
        min_heapify(arr, min, size);
    }
}

void build_minheap(vector<int>& arr, int size){
    for(int i = size/2; i>=0; i--)
        min_heapify(arr, i, size);
}

void heapsort(vector<int>& arr, int size){
    build_minheap(arr, size);
    for(int i = size-1; i>0; i--){
        //cout << arr[0] << " ";
        swap(arr[0], arr[i]);
        min_heapify(arr, 0, i);
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
    
    for(int i = n-1; i>=0; i--){
        cout << arr[i] << " ";
    }
    
    
    return 0;
}
