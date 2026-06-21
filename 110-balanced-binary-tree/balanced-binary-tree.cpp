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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int x=0,y=0;
        if(root->left)
         x=Height(root->left);
        if(root->right)
          y=Height(root->right);
        int height=abs(x-y);
        if(height>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};