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
void preorder(TreeNode*root,vector<int>&result){
    if(root==NULL)return ;
    result.push_back(root->val);
    if(root->left)preorder(root->left,result);
    if(root->right)preorder(root->right,result);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root==NULL)return result;
        if(root->left==NULL && root->right==NULL){
            result.push_back(root->val);
            return result;
        }
        preorder(root,result);
        return result;
    }
};