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
void Inorder(TreeNode* root,vector<int>&result){
    if(root==NULL) 
    return;
   
    if(root->left)
        Inorder(root->left,result);
     result.push_back(root->val);
    if(root->right)
        Inorder(root->right,result);
}
    int kthSmallest(TreeNode* root, int k) {
      vector<int>result;
      Inorder(root,result);

      return result[k-1];
    }
};