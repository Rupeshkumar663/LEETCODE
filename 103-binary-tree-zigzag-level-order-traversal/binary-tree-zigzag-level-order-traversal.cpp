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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>result;
       if(root==NULL){
        return result;
       }
       queue<TreeNode*>q;
       bool leftright=true;
       q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode*p=q.front();
                q.pop();
                if(leftright==true){
                    temp[i]=p->val;
                } else{
                    temp[size-1-i]=p->val;
                }
                if(p->left){
                   q.push(p->left);
                }
                 if(p->right){
                   q.push(p->right);
                }
            }
            leftright=!leftright;
            result.push_back(temp);
        }
        return result;
    }
};