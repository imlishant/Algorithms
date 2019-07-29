#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define for0(i,n) for(int i=0;i<n;++i)
#define for1(i,n) for(int i=1;i<=n;++i)
#define ford(i,n) for(int i=n-1;i>=0;--i)
#define forg(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
#define N 1000001


int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test;
	while(test--){
	    int n;
	    cin >> n;
	    vector<int> arr(n), L(n, 1);
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    int max = 1;
	    L[0] = 1;
	    for(int i = 1; i < n; i++){
	        for(int j = 0; j < i; j++){
	            if(arr[j] < arr[i] && (L[i] < 1 + L[j])){
	                L[i] = 1 + L[j];
	            }
	        }
	        if(max < L[i])
	            max = L[i];
	    }
	    cout << max << "\n";
	}
	
	
	return 0;
}
