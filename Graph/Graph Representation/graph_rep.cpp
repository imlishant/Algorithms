#include<bits/stdc++.h>

using namespace std;

int main(){
  map<int , vector< pair<int, int > > > adjList;  
  
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i ++){
    int u, v, w;                       // ver1, ver2 && weight
    cin >> u >> v >> w;
    // If graph is undirected:
    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
    // If graph is directed from u to v
    adjList[u].push_back(make_pair(v, w));
  }
  
  // Print Adjacency List
  map<int , vector< pair<int, int > > >::iterator it;
  for(it = adjList.begin() ; it != adjList.end() ; it++){
    cout << it->first << " : ";
    vector<pair<int, int> > neighbours = it->second;
    for(int i = 0 ; i < neighbours.size() ; i++){
      cout << "(" << neighbours[i].first << " " << neighbours[i].second << ")";
    }
    cout << endl;
  }
}
