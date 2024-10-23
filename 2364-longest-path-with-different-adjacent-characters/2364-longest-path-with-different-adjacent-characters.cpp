class Solution {
public:
    int dfs(unordered_map<int, list<int>>& mp, int src, int parent, string& s, int& time) {
        int longest = 0;
        int second_longest = 0;
        
        for (auto neigh : mp[src]) {
            if (neigh == parent) continue;  // Skip the parent
            
            int child_longest = dfs(mp, neigh, src, s, time);
            
            // If the characters of the current node and the child are the same, skip this path
            if (s[neigh] == s[src]) continue;
            
            // Update longest and second longest path
            if (child_longest > longest) {
                second_longest = longest;
                longest = child_longest;
            } else if (child_longest > second_longest) {
                second_longest = child_longest;
            }
        }
        
        // Calculate the longest path that passes through the current node
        int ans = 1 + longest + second_longest;
        time = max(time, ans);  // Update the maximum path length found so far
        
        // Return the longest path that starts at this node and goes downwards
        return 1 + longest;
    }

    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, list<int>> mp;
        
        // Build the adjacency list representation of the tree
        for (int i = 1; i < parent.size(); i++) {
            mp[parent[i]].push_back(i);
            mp[i].push_back(parent[i]);
        }
        
        int time = 0;
        dfs(mp, 0, -1, s, time);  // Start DFS from node 0, with no parent (-1)
        return time;
    }
};
