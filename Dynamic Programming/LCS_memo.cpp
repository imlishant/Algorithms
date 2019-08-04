#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x << "\n"
using namespace std;

const int num = 1000;
//int dp[][num] = {0};

int LCS(string &x, string &y, int m, int n, int dp[][num]){
    
    if(m == 0 || n == 0)
        return 0;
    else if(x[m-1] == y[n-1])
        dp[m][n] = 1 + LCS(x, y, m-1, n-1, dp);
    else{
        dp[m][n] = max(LCS(x,y,m,n-1, dp), LCS(x, y, m-1, n, dp));
    }
    return dp[m][n];
}

int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int m = x.size();
    int n = y.size();
    deb(m);
    deb(n);
    int dp[m][num];
    int ans = LCS(x, y, m, n, dp);
    cout << ans << "\n";
    return 0;
}