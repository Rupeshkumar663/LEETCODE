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
 //Time Compelxity: O(n)
 //Space Complexity: O(n) 
class Solution {
public:
   void preorder(TreeNode* root,vector<int>&result){
    if(root==NULL){
        return;
    }
    result.push_back(root->val);//push root in result
    if(root->left){//if satisfied this condtion then moves toward root left
        preorder(root->left,result);
    }
    if(root->right){//if satisfied this condtion then moves toward root right
        preorder(root->right,result);
     }
   }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;//
        preorder(root,result);//preorder order traversal function
        return result;
    }
};