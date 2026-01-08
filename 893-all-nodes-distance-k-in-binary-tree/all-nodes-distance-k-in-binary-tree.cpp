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
        if(!root)
          return;
       
        if(root->left){
            m[root->left]=root;
           Inorder(root->left,m);
        }
        if(root->right){
            m[root->right]=root;
           Inorder(root->right,m);
        }
    }
    void finddistance(int k,vector<int>&result,TreeNode* target,  unordered_map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty()){
            int n=q.size();
            if(k==0)
             break;
              while(n--){
               TreeNode* temp=q.front();
               q.pop();
               if(temp->left && !visited.count(temp->left->val)){
                q.push(temp->left);
                visited.insert(temp->left->val);
                }
              if(temp->right && !visited.count(temp->right->val)){
               q.push(temp->right);
                 visited.insert(temp->right->val);
                }
               if(m.count(temp) && !visited.count(m[temp]->val)){
                 q.push(m[temp]);
                 visited.insert(m[temp]->val);
                }
             }
             k--;
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*>m;
      vector<int>result;
      Inorder(root,m); 
      finddistance(k,result,target,m); 
      return result;
    }
};