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
 /*
 //Time Complexity:O(n)*O(n)=O(n*n)
 //Space Complexity: O(n)
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
     solve(root,store); //Space Complexity: O(n)
     for(int i=0;i<store.size()-1;i++){ //Time Complexity: O(n)
        int sum=store[i];
        for(int j=i+1;j<store.size();j++){ //Time Complexity: O(n)
            if(sum+store[j]==k){
                return true;
            }
        }
     }
     return false;
    }
};
 */

 //Time Complexity:O(n)*O(n)=O(n*n)
 //Space Complexity: O(n)
class Solution {
public:
   void solve(TreeNode* root,unordered_set<int>&s,int &k,bool &result){
    if(root==NULL){
        return ;
    }
    if(root->left){
        solve(root->left,s,k,result);
    }
    int temp=k-root->val;
    if(s.find(temp)!=s.end()){
        result=true;
        return;
    }
    s.insert(root->val);
    if(root->right){
        solve(root->right,s,k,result);
    }
   }
    bool findTarget(TreeNode* root, int k) {
     bool result=false;
     unordered_set<int>s;
     solve(root,s,k,result); 
     return result;
    }
};