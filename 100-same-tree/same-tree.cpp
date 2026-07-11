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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        } 
        if(p->val!=q->val){
            return false;
        }
      return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
*/
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
 bool solve(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL){//both null return true
        return true;
    }
    if(p==NULL || q==NULL){//if any one null return false
        return false;
    }
    if((p->val==q->val)&& p->left==NULL && p->right==NULL && q->left==NULL && q->right==NULL){
        return true;
    }
    if(p->val!=q->val){
        return false;
    }
    return solve(p->left,q->left) && solve(p->right,q->right);
 }
    bool isSameTree(TreeNode* p, TreeNode* q) {
      return  solve(p,q);//traverse all nodes of both tree Time Complexity: O(n)
    }
};