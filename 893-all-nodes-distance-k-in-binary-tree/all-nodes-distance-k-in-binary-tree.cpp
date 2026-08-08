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
 void Inorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m){
    if(root==NULL){
        return;
    }
    if(root->left){
        m[root->left]=root;
        Inorder(root->left,m);
    }
     if(root->right){
        m[root->right]=root;
        Inorder(root->right,m);
    }
  }

  void BFS(TreeNode* root, TreeNode* target, int k,unordered_map<TreeNode*,TreeNode*>&m,unordered_map<TreeNode*,bool>&visited,vector<int>&result){
    queue<TreeNode*>q;
    q.push(target);
    visited[target]=true;
    while(!q.empty()){
        int t=q.size();
        while(t--){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->left && visited[temp->left]==false){
                visited[temp->left]=true;
                q.push(temp->left);
            }
            if(temp->right && visited[temp->right]==false){
                 visited[temp->right]=true;
                q.push(temp->right);
            }
            if(m[temp] && visited[m[temp]]==false){
                 visited[m[temp]]=true;
                q.push(m[temp]);
            }
         }
         k--;
         if(k==0)
           break;
     }
      while(!q.empty()){
        TreeNode* p=q.front();
        q.pop();
        result.push_back(p->val);
      }
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*>m;
        Inorder(root,m);
        unordered_map<TreeNode*,bool>visited;
        vector<int>result;
        BFS(root,target,k,m,visited,result);
        return result;
    }
};