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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
       unordered_map<int,TreeNode*>m;
        unordered_set<int>s;
        for(auto &x:descriptions){
            int parent=x[0];
            int c=x[1];
            int isLeft=x[2];
            if(m.find(parent)==m.end())
                m[parent]=new TreeNode(parent);
            if(m.find(c)==m.end())
                m[c]=new TreeNode(c);
            if(isLeft==1)
                m[parent]->left=m[c];
            else
                m[parent]->right=m[c];
            s.insert(c);
        }
        for(auto &temp:m){
            if(s.find(temp.first)==s.end())
                return temp.second;
        }
        return nullptr; 
    }
};