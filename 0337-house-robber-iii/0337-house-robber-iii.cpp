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
private:
pair<int,int> maxprofit(TreeNode* root){// take root,not take root
    if(root==NULL) return {0,0};

    pair<int,int> left=maxprofit(root->left);
    pair<int,int> right=maxprofit(root->right);

    int takeroot=root->val+left.second+right.second;
    int noroot=max(left.first,left.second)+max(right.first,right.second);
    return {takeroot,noroot};
}
public:
    int rob(TreeNode* root) {
        return max(maxprofit(root).first,maxprofit(root).second);
    }
};