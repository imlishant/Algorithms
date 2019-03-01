#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        int temp = a[i];
        int j ;
        for(j = i; j > 0; j--){
            if(temp < a[j-1]){
                a[j] = a[j-1];
            }else break;
        }
        a[j] = temp;
    }
}

int main()
{
    vector<int> a = {23, 34, 12, 98, 45};
    insertion_sort(a);
    vector<int>::iterator it;
    for(it = a.begin(); it != a.end(); ++it){
        cout << *it << " ";
    }
    return 0;
}
