/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val, {});
            return clone;
        }

        Node* clone = new Node(node->val, {});
        mp[node] = clone;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            for(auto neighbor: cur->neighbors){
                if(mp.find(neighbor) == mp.end()){
                    mp[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }

                mp[cur]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};