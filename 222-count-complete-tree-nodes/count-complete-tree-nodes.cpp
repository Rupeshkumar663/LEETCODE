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
    void Inorder(TreeNode* root,int&count){
        if(!root)
           return;
        if(root)
         count++;
         if(root->left)
          Inorder(root->left,count);
        if(root->right)
          Inorder(root->right,count);
    }
    int countNodes(TreeNode* root) {
      int count=0;
      Inorder(root,count);
      return count;
    }
};