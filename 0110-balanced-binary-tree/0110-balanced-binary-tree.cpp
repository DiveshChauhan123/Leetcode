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
int height(TreeNode*root){
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int l=height(root->left);
        int r=height(root->right);
        int diff=abs(l-r);
        bool a=(diff<=1);
        bool b=isBalanced(root->left);
        bool c=isBalanced(root->right);
        return (a && b && c);
    }
};