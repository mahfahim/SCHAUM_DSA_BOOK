#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform topological sort on the graph
void topologicalSort(vector<vector<int>>& graph, int numNodes) {
    vector<int> indegree(numNodes, 0);

    // Step 1: Calculate the indegree of each node
    for (int i = 0; i < numNodes; ++i) {
        for (int j : graph[i]) {
            indegree[j]++;
        }
    }

    // Step 2: Add nodes with 0 indegree to the queue
    queue<int> q;
    for (int i = 0; i < numNodes; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Perform the topological sort
    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Step 5: For each neighbor, reduce the indegree
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check if topological sort is possible (no cycles)
    if (topoOrder.size() != numNodes) {
        cout << "The graph has a cycle and a topological sort is not possible." << endl;
        return;
    }

    // Step 6: Print the topological order
    cout << "Topological Sort Order: \n";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int numNodes, numEdges;
   // cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes);

   // cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    topologicalSort(graph, numNodes);

    return 0;
}

/*
Enter the number of nodes and edges: 6 6
Enter the edges (format: from to):
5 2
5 0
4 0
4 1
2 3
3 1

*/


/*
Topological Sort Order: 4 5 2 3 1 0

*/