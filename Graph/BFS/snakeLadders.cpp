#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>>& g, int start){
    bool vis[110];
    memset(vis, false, sizeof(vis));

    int dist[110];
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    vis[start] = true;
    q.push(start);
    dist[start] = 0;
    while(q.empty() == false){
        int temp = q.front();
        q.pop();

        for(int child : g[temp]){
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
                dist[child] = dist[temp] + 1;
            }
        }
    }
    return dist[100];
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n;
        vector<vector<int>> ladders(n);
        for(int i = 0; i < n; i++){
            ladders[i].resize(2);
            cin >> ladders[i][0] >> ladders[i][1];
        }
        cin >> m;
        vector<vector<int>> snakes(m);
        for(int i = 0; i < m; i++){
            snakes[i].resize(2);
            cin >> snakes[i][0] >> snakes[i][1];
        }
        //make graph
        vector<vector<int>> g(110);
        // all edges.
        for(int i = 1; i <= 100; i++){
            for(int j = i+1; j <= i+6; j++){
                if(j <= 100){
                    g[i].push_back(j);
                }
            }
        }
        // ladders.
        for(int i = 0; i < n; i++){
            int a = ladders[i][0];
            int b = ladders[i][1];
            g[a].clear();
            for(int j = a - 6; j <= a; j++){
                if(j >= 1){
                    g[j].erase(remove(g[j].begin(), g[j].end(), a), g[j].end());
                    g[j].push_back(b);
                }
            }
        }
        // snakes.
        for(int i = 0; i < m; i++){
            int a = snakes[i][0];
            int b = snakes[i][1];
            g[a].clear();
            for(int j = a - 6; j <= a; j++){
                if(j >= 1){
                    g[j].erase(remove(g[j].begin(), g[j].end(), a), g[j].end());
                    g[j].push_back(b);
                }
            }
        }
        cout << bfs(g, 1) << "\n";
    }

    return 0;
}