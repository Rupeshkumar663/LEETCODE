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
       int hleft=0,hright=0;
       if(root->left){
         hleft=Height(root->left);
       }
        if(root->right){
         hright=Height(root->right);
       }
       int temp=abs(hleft-hright);
       if(temp>1){
        return false;
       }
       return isBalanced(root->left) && isBalanced(root->right);
    }
};