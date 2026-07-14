/*class Solution {
public:
    bool check(TreeNode* root, long long low, long long high) {
        if(!root) 
        return true;
        if(root->val<=low || root->val>=high) 
        return false;
        return check(root->left, low, root->val) && check(root->right, root->val,high);
    }

    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};*/

class Solution {
public:
   void Inorder(TreeNode*root,long long &prev,bool &result){
    if(root==NULL){
        return ;
    }
    if(root->left){
        Inorder(root->left,prev,result);
    }
    
    if( prev>=root->val){
        result=false;
        return ;
    }
    prev=root->val;
     if(root->right){
        Inorder(root->right,prev,result);
     }
}

    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        long long prev=LLONG_MIN;
        bool result=true;
      Inorder(root,prev,result);
      return result;
    }
};