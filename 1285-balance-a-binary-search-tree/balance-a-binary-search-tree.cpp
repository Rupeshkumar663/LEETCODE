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
/*class Solution {
public:
  int height(TreeNode*root){
    if(!root){
         return 0;
    }
    int hl=height(root->left);
    int hr=height(root->right);
     if(hl>hr)
        return hl+1;
     return  hr+1;
  }

  TreeNode* RightRotation(TreeNode* y){
    TreeNode* x=y->left;
    TreeNode*T2=x->right;

    x->right=y;
    y->left=T2;
    return x;
  }

  TreeNode* LeftRotation(TreeNode* y){
    TreeNode* x=y->right;
    TreeNode*T2=x->left;

    x->left=y;
    y->right=T2;
    return x;
  }
 TreeNode* Balanced(TreeNode*root){
    if(!root)
      return NULL;
      Balanced(root->left);

      int bf=height(root->left)-height(root->right);
      if(bf>1){
        if(height(root->left->left)>=height(root->left->right))
          return  RightRotation(root);
        else{
          root->left=LeftRotation(root->left);
           return RightRotation(root);
        }
      }


       if(bf<-1){
        if(height(root->right->right)>=height(root->right->left))
           return  LeftRotation(root);
        else{
           root->right=RightRotation(root->right);
           return LeftRotation(root);
        }
      }
      return root;
  }
    TreeNode* balanceBST(TreeNode* root) {
        return Balanced(root);
      
    }
};
*/
class Solution {
public:
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    
    TreeNode* buildTree(int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildTree(0, nodes.size() - 1);
    }
};