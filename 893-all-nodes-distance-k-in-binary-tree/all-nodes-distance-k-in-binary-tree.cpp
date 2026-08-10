/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Time Complexity: O(n)
class Solution {
public:
 unordered_map<TreeNode*,TreeNode*>parent;
  void Inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    if(root->left){
        parent[root->left]=root;
        Inorder(root->left);
    }

    if(root->right){
        parent[root->right]=root;
         Inorder(root->right);
    }
  }
   void BFS(TreeNode* root, TreeNode* target, int k,vector<int>&result,unordered_set<TreeNode*>&visited){
    if(k==0){
        result.push_back(target->val);
        return;
    }
    queue<TreeNode*>q;
    q.push(target);
    visited.insert(target);
    while(!q.empty()){
      int t=q.size();
      while(t--){
        TreeNode* temp=q.front();
        q.pop();
        if(temp->left && visited.find(temp->left)==visited.end()){
            q.push(temp->left);
            visited.insert(temp->left);
         }
         if(temp->right && visited.find(temp->right)==visited.end()){
            q.push(temp->right);
            visited.insert(temp->right);
         }
         if(parent[temp] && visited.find(parent[temp])==visited.end()){
            q.push(parent[temp]);
            visited.insert(parent[temp]);
         }
      }
      k--;
      if(k==0)
        break;
     }
     while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        result.push_back(temp->val);
     }
   }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        Inorder(root);
        vector<int>result;
        unordered_set<TreeNode*>visited;
        BFS(root,target,k,result,visited);
        return result;
    }
};