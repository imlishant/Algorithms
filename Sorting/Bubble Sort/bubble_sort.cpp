#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    vector<int> a = {23, 34, 12, 98, 45};
    bubble_sort(a);
    vector<int>::iterator it;
    for(it = a.begin(); it != a.end(); ++it){
        cout << *it << " ";
    }
    return 0;
}
