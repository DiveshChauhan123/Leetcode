class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x], parent);  // Path compression
    }

    void unionSets(int x, int y, vector<int>& parent, vector<int>& rank) {  // Renamed from 'union'
        int i = find(x, parent);
        int j = find(y, parent);
        if (i == j) return;
        if (rank[i] > rank[j]) {
            parent[j] = i;
        } else if (rank[i] < rank[j]) {
            parent[i] = j;
        } else {
            parent[i] = j;
            rank[j]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        // Initialize parent array
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Process all '==' equations
        for (auto& s : equations) {
            if (s[1] == '=') {
                unionSets(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }

        // Process all '!=' equations
        for (auto& s : equations) {
            if (s[1] == '!') {
                int x = find(s[0] - 'a', parent);
                int y = find(s[3] - 'a', parent);
                if (x == y) return false;
            }
        }

        return true;
    }
};
