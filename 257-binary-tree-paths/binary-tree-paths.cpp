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
 //Time Complexity: O(n)
 //Space Complexity:O(n)
class Solution {
public:
 void solve(TreeNode* root,vector<string>&result,string s){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
       s += to_string(root->val);
        result.push_back(s);
        s.pop_back();
        return;
    }
    s += to_string(root->val) + "->";
    if(root->left){
        solve(root->left,result,s);
    }
    if(root->right){
        solve(root->right,result,s);
    }

 }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        //using Tree Traversal
        solve(root,result,"");//Time Complexity: O(n)
        return result;
    }
};