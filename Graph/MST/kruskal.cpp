#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int *parent, int index) {
    if (parent[index] == index) 
        return index;
    return findParent(parent, parent[index]);
}
/*
void makeParent(int *parent, int size) {
    //vector<int> parent(size);
    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}
*/
void kruskals(Edge *input, int n, int E) {
    sort(input, input + E, compare);

    Edge *output = new Edge[n-1];
    int count = 0;
    int i = 0;
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    while(count < n-1) {
        Edge currentEdge = input[i];
        int sourceParent = findParent(parent, currentEdge.src);
        int destParent = findParent(parent, currentEdge.dest);

        if (sourceParent != destParent) {
            output[count] = currentEdge;
            parent[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    // to output vertices in order....
    sort(output, output + n-1, [](Edge e1, Edge e2) {return e1.src < e2.src;});
    for (int i = 0; i < n-1; i++) {
        cout << output[i].src << " " << output[i].dest << " "
            << output[i].weight << "\n";
    }
}

int main() 
{
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E];
    for (int i = 0; i < E; i++) {
        cin >> input[i].src;
        cin >> input[i].dest;
        cin >> input[i].weight;
    }
    cout << "***********************\n";
    kruskals(input, n, E);
    return 0;
}
