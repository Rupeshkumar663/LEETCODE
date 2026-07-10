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
 //Time COmplexity: O(logn)
 //Space Complexity: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        } 
         if(root->val==val){//if condition satiefied then return root
            return root;
         } else if(root->val>val){//if condition satified then moves toward left 
            return searchBST(root->left,val);
         } else{//if condition satified then moves toward right
            return searchBST(root->right,val);
         }
        return NULL;//if I  do not get then return Null
    }
};