#include <bits/stdc++.h>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::endl;
/*
 Topological Sort:
 -----------------
 - Topological sort is a linear ordering of the vertices of a Directed Acyclic Graph (DAG) 
   such that for every directed edge u -> v, vertex u appears before v in the ordering.
 - It is only defined for DAGs (Directed Acyclic Graphs). If the graph has a cycle, 
   a valid topological order does not exist.

 Kahn's Algorithm:
 -----------------
 - Kahn’s Algorithm is a BFS-based approach to perform topological sort.
 - It uses the concept of **in-degree** (the number of incoming edges for a vertex).
 
 Steps:
 1. Compute the in-degree of all vertices.
 2. Initialize a queue with all vertices having in-degree 0 (no dependencies).
 3. While the queue is not empty:
      - Remove a vertex from the queue and add it to the topological ordering.
      - For each outgoing edge from this vertex to its neighbor, reduce the neighbor’s in-degree by 1.
      - If the neighbor’s in-degree becomes 0, add it to the queue.
 4. If all vertices are processed, the result is a valid topological order.
    Otherwise, the graph has a cycle, and no topological order exists.

 Time Complexity: O(V + E), where V = number of vertices, E = number of edges
 Space Complexity: O(V + E) for storing graph and auxiliary structures
*/

vector<int> topologicalSortKahn(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    // Build graph and compute in-degree
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topoOrder.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    // Check if topological sort is possible (i.e., no cycle exists)
    if ((int)topoOrder.size() != n) {
        cout << "Graph has a cycle, topological sort not possible.\n";
        return {};
    }

    return topoOrder;
}

// Example usage
int main() {
    int n = 6; // number of vertices
    vector<vector<int>> edges = {
        {5, 2}, {5, 0},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };

    vector<int> result = topologicalSortKahn(n, edges);

    if (!result.empty()) {
        cout << "Topological Order: ";
        for (int v : result) cout << v << " ";
        cout << endl;
    }
    return 0;
}

/*
 Example Graph:
     5 → 0 ← 4
     ↓       ↑
     2 → 3 → 1
     ↓
     (edges given above)

 Possible Topological Orders:
 - 4 5 2 3 1 0
 - 5 4 2 3 1 0
 (and others depending on processing order of queue)

*/
