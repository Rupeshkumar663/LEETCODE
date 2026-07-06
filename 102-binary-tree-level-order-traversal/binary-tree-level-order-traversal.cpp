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
 //Space COmplexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root){
       vector<vector<int>>result;
       queue<TreeNode*>q;// Queue used for BFS traversal.level
       if(root==NULL){//return empty array when tree is empty
        return {};
       }
       q.push(root);
       while(!q.empty()){//Time Complexity: O(n)
          int t=q.size(); // Number of nodes at the current level.
          vector<int>num;// Stores values of the current level.
          while(t--){//Time Complexity: O(1)
            TreeNode* temp=q.front();
            q.pop();
            num.push_back(temp->val);
            if(temp->left){   // Push left child if it exists.
              q.push(temp->left);
            }
            if(temp->right){   // Push right child if it exists.
              q.push(temp->right);
            }
          }
         result.push_back(num);// Store the current level in the final result.
       }
       return result;
    }
};