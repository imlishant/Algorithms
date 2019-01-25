#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter number of Integers: ";
    int num;
    cin >> num;
    cout << "Enter an array of Integers: \n";
    int arr[num];
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    cout << "Enter number to be searched : ";
    int srch_num;
    cin >> srch_num;
    int flag = 0;
    int pos = 0;
    for(int i = 0; i < num; i++){
        if(arr[i] == srch_num){
            flag = 1;
            pos = i + 1;
            break;
        }
    }

    if(flag == 1){
        cout << "found the number " << srch_num << " at position :: " << pos << endl;
    }else cout << "NOT found!!" << endl;

    return 0;
}
