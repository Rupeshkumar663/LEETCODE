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
int index=0;
TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start,int end,unordered_map<int,int>&m){
    if(start>end)
     return NULL;
       int temp=preorder[index++];
       TreeNode* ans=new TreeNode(temp);
        int mid=m[temp];

       ans->left= construct(preorder,inorder,start,mid-1,m);
       ans->right= construct(preorder,inorder,mid+1,end,m);
    return ans;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<preorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode*result=construct(preorder,inorder,0,inorder.size()-1,m);
        return result;
    }
};