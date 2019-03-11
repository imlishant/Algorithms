#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int start, int mid, int end){
    int p = start, q = mid+1;
    vector<int> temp(end-start+1);
    int k = 0;
    while(p<=mid && q<=end){
        if(a[p] < a[q]){
            temp[k++] = a[p++];
        }else{
            temp[k++] = a[q++];
        }
    }
    while(p<=mid){
        temp[k++] = a[p++];
    }
    while(q<=end){
        temp[k++] = a[q++];
    }
    for(int i=0; i<k; i++){
        a[start++] = temp[i];
    }
    
}

void mergesort(vector<int>& a, int start, int end){
    int mid = (start + end) / 2;
    if(start < end){
        mergesort(a, start, mid);
        mergesort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    mergesort(a, 0, n-1);
    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
    cin.ignore();
    cin.get();
    return 0;
}
