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
 //T.C-O(N)
 //S.C-O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
      vector<vector<int>>result;
      queue<TreeNode*>q;
      q.push(root);
       bool right_to_left=false;
       while(!q.empty()){
           int t=q.size();
           vector<int>temp;
           while(t--){
            TreeNode *p=q.front();
            q.pop();
             temp.push_back(p->val);
            if(p->left)
              q.push(p->left);
             if(p->right)
               q.push(p->right);
           }   
             if(right_to_left){
                reverse(temp.begin(),temp.end());
             }
             right_to_left=!right_to_left;
             result.push_back(temp);
       }
       return result;
    }
};