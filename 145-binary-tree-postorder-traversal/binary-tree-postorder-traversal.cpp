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
void postorder(TreeNode* root,vector<int>&result){
    if(root==NULL){
        return;
    }
    if(root->left){//if satisfied this condtion then moves toward root left
        postorder(root->left,result);
    }
    if(root->right){//if satisfied this condtion then moves toward root right
        postorder(root->right,result);
     }
      result.push_back(root->val);//push root in result
   }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;//
        postorder(root,result);//postorder order traversal function
        return result;
    }
};