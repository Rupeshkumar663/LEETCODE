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
 int add=0;
 void sum(TreeNode*root){
     if(!root)
       return;
        if(root->right)
        sum(root->right);

        add+=root->val;
        root->val=add;

        if(root->left)
        sum(root->left);
}
    TreeNode* bstToGst(TreeNode* root) {
        sum(root);
        return root;
    }
};