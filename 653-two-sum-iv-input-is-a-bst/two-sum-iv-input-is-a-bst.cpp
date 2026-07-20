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
   void solve(TreeNode* root,vector<int>&store){
    if(root==NULL){
        return ;
    }
    if(root->left){
        solve(root->left,store);
    }
    store.push_back(root->val);
    if(root->right){
        solve(root->right,store);
    }
   }
    bool findTarget(TreeNode* root, int k) {
     vector<int>store;
     solve(root,store);
     for(int i=0;i<store.size()-1;i++){
        int sum=store[i];
        for(int j=i+1;j<store.size();j++){
            if(sum+store[j]==k){
                return true;
            }
        }
     }
     return false;
    }
};