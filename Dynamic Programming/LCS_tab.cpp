#include <bits/stdc++.h>
using namespace std;

int LCS(string &X, string &Y){
    int m = X.size();
    int n = Y.size();
    int L[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1]){
                L[i][j] = 1 + L[i-1][j-1];
            }
            else{
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    return L[m][n];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int lcs = LCS(s1, s2);
    cout << lcs << "\n";
    return 0;
}