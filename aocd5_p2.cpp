#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> generateTopologicalOrder(const vector<pair<int, int>>& rules) {
    unordered_map<int, vector<int>> adj;   // Adjacency list for the graph
    unordered_map<int, int> inDegree;       // In-degree for each node
    unordered_set<int> allPages;            // To keep track of all unique pages

    // Build the graph
    for (const auto& rule : rules) {
        adj[rule.first].push_back(rule.second);
        inDegree[rule.second]++;
        allPages.insert(rule.first);
        allPages.insert(rule.second);
    }

    // Queue for Kahn's algorithm (topological sort)
    queue<int> q;
    for (int page : allPages) {
        if (inDegree[page] == 0) {
            q.push(page);
        }
    }

    // Resultant topological order
    vector<int> topoOrder;

    while (!q.empty()) {
        int page = q.front();
        q.pop();
        topoOrder.push_back(page);

        for (int neighbor : adj[page]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the number of pages in topological order is less than the total number of pages,
    // it means there is a cycle and topological sort is not possible
    if (topoOrder.size() != allPages.size()) {
        cout << "There is a cycle in the graph!" << endl;
        return {};
    }

    return topoOrder;
}

int main() {
    // Input rules (X must come before Y)
    vector<pair<int, int>> rules = {
        {47, 53}, {97, 13}, {97, 61}, {97, 47}, {75, 29}, {61, 13}, {75, 53},
        {29, 13}, {97, 29}, {53, 29}, {61, 53}, {97, 53}, {61, 29}, {47, 13},
        {75, 47}, {97, 75}, {47, 61}, {75, 61}, {47, 29}, {75, 13}, {53, 13}
    };

    // Step 1: Generate the topological order based on the rules
    vector<int> topoOrder = generateTopologicalOrder(rules);

    if (!topoOrder.empty()) {
        // Step 2: Output the long array (topologically sorted elements)
        cout << "The long array that follows the rules: ";
        for (int page : topoOrder) {
            cout << page << " ";
        }
        cout << endl;
    }

    return 0;
}
