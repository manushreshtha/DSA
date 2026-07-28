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
    int dm=0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dm;
    }
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        dm=max(dm,lh+rh);
        return max(lh,rh)+1;
    }
};