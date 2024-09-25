class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x], parent);  // Path compression
    }

    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);  // Find the root of x
        int y_parent = find(y, parent);  // Find the root of y

        if (x_parent == y_parent) return;  // Already in the same set

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > connections.size()) return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        // Initialize each node's parent to itself
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int connectedComponents = n;

        for (int i = 0; i < connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];

            if (find(x, parent) != find(y, parent)) {
                unionSet(x, y, parent, rank);
                connectedComponents--;
            }
        }

        return connectedComponents - 1;  // Number of operations required to connect all components
    }
};
