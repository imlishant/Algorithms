#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void bruteSearch(string T, string W)
{
    if(W == "" || T == ""){
        cout << "\n-1\n";
        return;
    }

    int i = 0;
    bool match;
    bool flag = false;
    int wordlen = W.length();
    int textlen = T.length();
    while(i < textlen - wordlen + 1)
    {
        match = true;

        for(int j = 0; j < wordlen; j++){
            if(W[j] != T[i+j]){
                match = false;
                break;
            }
        }
        if(match){
            cout << i+1 << " ";
            flag = 1;
        }
        
        i++;
    }
    if(!flag)
        cout << "\n-1\n";
}

int main()
{
    string T, W;
    cout << "Enter strings: \n";
    cin >> T;
    cin >> W;
    bruteSearch(T, W);

    return 0;
}