/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
        bool a=true;
        while(!q.empty()){
            int s=q.size();
            vector<int>ans;
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(a){
                result.push_back(ans);
                a=false;
            }
            else{
                reverse(ans.begin(),ans.end());
                a=true;
                result.push_back(ans);
            }
        }
        return result;
    }
};