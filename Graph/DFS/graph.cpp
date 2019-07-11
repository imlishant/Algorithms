#include <bits/stdc++.h>
using namespace std;
#define n 1000
vector<int> adlist[n+1];
bool vis[n+1] = {0};

int dfs(int p, int* arr){
    int max_val = arr[p];
    vis[p] = 1;
    for(int i = 0; i < adlist[p].size(); i++){
        int c = adlist[p][i];
        if(!vis[c]){
            dfs(c, arr);
            //max_val = max(max_val, dfs(c, arr));
            max_val = max(max_val, arr[c]);
        }
    }
    arr[p]=max_val;
    //return max_val;
}

int main()
{
    int N;
    int E;
    cout << "Enter N and E :: ";
    cin >> N;
    cin >> E;
    int a, b;
    int value;
    cout << "Enter edges \n";
    for(int i = 0; i < E; i++){
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }
    cout << "Enter value \n";
    int arr[N+1];
    for(int i = 1; i <= N; i++){
        cin>>arr[i];
    }
    value = dfs(1, arr);
    cout << "\nvalue :: " << value << "\n";
    cin.ignore();
    cin.get();
    return 0;
}