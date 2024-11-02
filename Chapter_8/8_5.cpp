#include <iostream>
#include <vector>
#include <optional>

using namespace std;

// Function to find the location of a node in a linked list representation of the graph
optional<int> find(const vector<int>& node, const vector<int>& next, int start, int value) {
    int current = start;
    while (current != -1) {
        if (node[current] == value) {
            return current; // Found the node
        }
        current = next[current];
    }
    return nullopt; // Node not found
}

// Function to find the location of the edge (A, B)
void findEdge(const vector<int>& node, const vector<int>& next, const vector<int>& adj, int start, int a, int b, optional<int>& loc) {
    optional<int> loca = find(node, next, start, a); // Find location of A
    optional<int> locb = find(node, next, start, b); // Find location of B

    if (!loca.has_value() || !locb.has_value()) {
        loc = nullopt; // If A or B is not found, set loc to NULL
    } else {
        // Assume adj[loca.value()] gives the starting point for the linked list of edges
        loc = find(node, next, adj[loca.value()], b); // Find location of edge (A, B)
    }
}

int main() {
    // Sample graph representation
    vector<int> node = {1, 2, 3, 4}; // Graph nodes
    vector<int> next = {1, 2, -1, -1}; // Next pointers (-1 indicates end of list)
    vector<int> adj = {1, 3}; // Adjacency list for edges
    int start = 0; // Starting point in the list
    int a = 1; // First node of the edge
    int b = 2; // Second node of the edge
    optional<int> loc; // Location of the edge

    // Call to findEdge
    findEdge(node, next, adj, start, a, b, loc);

    // Output the result
    if (loc.has_value()) {
        cout << "Edge (" << a << ", " << b << ") found at location: " << loc.value() << endl;
    } else {
        cout << "Edge (" << a << ", " << b << ") not found." << endl;
    }

    return 0;
}
