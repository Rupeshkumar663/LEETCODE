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
class Solution {
public:

TreeNode* construct(vector<int>& postorder, vector<int>& inorder, int start,int end,unordered_map<int,int>&m,int& index){
    if(start>end)
     return NULL;
       int temp=postorder[index--];
       TreeNode* ans=new TreeNode(temp);
        int mid=m[temp];

       ans->right= construct(postorder,inorder,mid+1,end,m,index);
       ans->left= construct(postorder,inorder,start,mid-1,m,index);
    return ans;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode*result=construct(postorder,inorder,0,inorder.size()-1,m,index);
        return result;
    }
};