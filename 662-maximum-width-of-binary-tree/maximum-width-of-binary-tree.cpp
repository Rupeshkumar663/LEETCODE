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
  typedef unsigned long long ll;
  void BFS(TreeNode* root,int &result){
    queue<pair<ll,TreeNode*>>q;
    q.push({0,root});
     while(!q.empty()){
        int t=q.size();
        ll x1=q.front().first;
        ll x2=q.back().first;
        result=max(result,(int)(x2-x1));
        while(t--){
            auto[index,node]=q.front();
            q.pop();
            if(node->left){
                q.push({2*index+1,node->left});
            }
            if(node->right){
                q.push({2*index+2,node->right});
            }
        }
     }
  }
    int widthOfBinaryTree(TreeNode* root){
      int result=0;
      BFS(root,result);
      return result+1;
    }
};