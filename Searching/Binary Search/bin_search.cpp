#include <bits/stdc++.h>

using namespace std;

int bin_search(int arr[], int l, int r, int data){
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == data)
            return mid;
        if(arr[mid] > data){
            r = mid - 1;
        }else l = mid + 1;

    }
    return -1;
}

int main()
{
    int arr[] = {23, 45, 98, 93, 967, 920, 804};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter data :: ";
    int data;
    cin >> data;
    int index = bin_search(arr, 0, n - 1, data);
    if(index == -1){
        cout << "NOT FOUND!!!!!!" << endl;
    }else cout << "Found at index " << index + 1 << endl;

    return 0;
}
