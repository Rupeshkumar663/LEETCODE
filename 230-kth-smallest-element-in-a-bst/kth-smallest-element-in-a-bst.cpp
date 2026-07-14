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
void Inorder(TreeNode* root,vector<int>&result){
    if(root==NULL) 
    return;
   
    if(root->left)
        Inorder(root->left,result);
     result.push_back(root->val);
    if(root->right)
        Inorder(root->right,result);
}
    int kthSmallest(TreeNode* root, int k) {
      vector<int>result;
      Inorder(root,result);
      return result[k-1];
    }
};*/
/*class Solution {
public:
    int Inorder(TreeNode* root,int &k){
        if(root==NULL)
         return -1;

        int left=Inorder(root->left,k);
        if(left!=-1) 
        return left;
        k--;
        if(k==0) 
          return root->val;
        return Inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k){
        return Inorder(root,k);
    }
};*/
//Time Complexity: O(n)
//Space Complexity: O(n)
/*class Solution {
public:
     void Inorder(TreeNode* root,vector<int>&result){
        if(root==NULL){
            return ;
        }
        if(root->left){
            Inorder(root->left,result);
        }
        result.push_back(root->val);
        if(root->right){
            Inorder(root->right,result);
        }
     }
    int kthSmallest(TreeNode* root, int k){
        vector<int>result;
        Inorder(root,result);
        return result[k-1];
    }
};*/

//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
     void Inorder(TreeNode* root,int &k,int &result,int &count){
        if(root==NULL){
            return ;
        }
        if(root->left){
            Inorder(root->left,k,result,count);
        }
             count++;
            if(count==k){
                result=root->val;
                return;
            }
    
        if(root->right){
            Inorder(root->right,k,result,count);
        }
     }
    int kthSmallest(TreeNode* root, int k){
        int result=0;
        int count=0;
        Inorder(root,k,result,count);
        return result;
       
    }
};