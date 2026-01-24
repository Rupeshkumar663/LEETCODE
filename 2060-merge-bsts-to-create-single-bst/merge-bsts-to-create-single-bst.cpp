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
class Solution{
public:
    
    unordered_map<int,TreeNode*> mp;
    unordered_set<int> children;
    
    bool validBST(TreeNode* root,long mn,long mx){
        if(!root)
            return true;
        if(root->val<=mn || root->val>=mx)
            return false;
        return validBST(root->left,mn,root->val) &&
               validBST(root->right,root->val,mx);
    }
    
    TreeNode* dfs(TreeNode* root){
        if(!root)
            return NULL;
        
        if(!root->left && !root->right && mp.count(root->val)){
            TreeNode* t=mp[root->val];
            root->left=t->left;
            root->right=t->right;
            mp.erase(root->val);
        }
        
        root->left=dfs(root->left);
        root->right=dfs(root->right);
        return root;
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees){
        for(auto t:trees){
            mp[t->val]=t;
            if(t->left) children.insert(t->left->val);
            if(t->right) children.insert(t->right->val);
        }
        
        TreeNode* root=NULL;
        for(auto t:trees){
            if(!children.count(t->val)){
                root=t;
                break;
            }
        }
        
        if(!root)
            return NULL;
        
        mp.erase(root->val);
        root=dfs(root);
        
        if(!mp.empty())
            return NULL;
        
        if(!validBST(root,LONG_MIN,LONG_MAX))
            return NULL;
        
        return root;
    }
};
