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
    vector<vector<int>> levelOrder(TreeNode* root){
       vector<vector<int>>result;
       queue<TreeNode*>q;
       if(root==NULL){
        return {};
       }
       q.push(root);
       while(!q.empty()){
          int t=q.size();
          vector<int>num;
          while(t--){
            TreeNode* temp=q.front();
            q.pop();
            num.push_back(temp->val);
            if(temp->left){
              q.push(temp->left);
            }
            if(temp->right){
              q.push(temp->right);
            }
          }
         result.push_back(num);
       }
       return result;
    }
};