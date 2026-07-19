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
/*class Solution {
public:
  TreeNode* create(TreeNode* root,int v){
    if(root==NULL){
         return new TreeNode(v);
    } 
    if(root->val>v){
        root->left=create(root->left,v);
    }
    if(root->val<=v){
        root->right=create(root->right,v);
    }
    return root;
  }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        for(int i=0;i<preorder.size();i++){
           root=create(root,preorder[i]);
        }
        return root;
    }
};*/

//Time Complexity: O(nlogn)
//Space COmpleixty: O(1)
class Solution {
public:
    TreeNode* createBst(TreeNode* root,int value){
        if(root==NULL){
            return new TreeNode(value);
        }
        if(root->val>value){
            root->left=createBst(root->left,value);
        }else{
            root->right=createBst(root->right,value);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      TreeNode *root=NULL;
      for(int i=0;i<preorder.size();i++){//Time Complexity: O(n)
        root=createBst(root,preorder[i]);////Time Complexity: O(logn)
      }
      return root;
    }
};