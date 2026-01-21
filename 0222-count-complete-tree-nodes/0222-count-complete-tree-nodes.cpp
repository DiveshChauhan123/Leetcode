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
void noofnodes(TreeNode*root,int &count){
    if(root==NULL){
        return ;
    }
    count++;
    noofnodes(root->left,count);
    noofnodes(root->right,count);
}
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        return l+r+1;
        
    }
};