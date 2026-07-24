/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* lowestCommon(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL){
        return NULL;
        }
    if(root->val==p->val || root->val==q->val){
        return root;
    }
    TreeNode* left=lowestCommon(root->left,p,q);
    TreeNode* right=lowestCommon(root->right,p,q);
    if(left && right)
       return root;
    if(left)
     return left;
    return right;
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommon(root,p,q);
    }
};