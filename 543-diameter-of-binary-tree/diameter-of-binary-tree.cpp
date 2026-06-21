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
int Height(TreeNode* root){
     if(root==NULL){
        return 0;
     } 
     int lh=Height(root->left);
     int rh=Height(root->right);
     return 1+max(lh,rh);
   }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int h1=0,h2=0;
        int leftH=root->left?Height(root->left):0;
        int rightH=root->right?Height(root->right):0;
        int diameter=leftH+rightH;
        if(root->left)
        h1=diameterOfBinaryTree(root->left);
        if(root->right)
        h2=diameterOfBinaryTree(root->right);
        return max(diameter,max(h1,h2));
    }
};