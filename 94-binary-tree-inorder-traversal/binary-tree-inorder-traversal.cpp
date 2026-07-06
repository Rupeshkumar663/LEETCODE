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
 void inorder(TreeNode* root,vector<int>&result){
    if(root==NULL){
        return;
    }
    if(root->left){//if satisfied this condtion then moves toward root left
        inorder(root->left,result);
    }
    result.push_back(root->val);//push root in result
    if(root->right){//if satisfied this condtion then moves toward root right
        inorder(root->right,result);
     }
   }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;//
        inorder(root,result);//inorder order traversal function
        return result;
    }
};