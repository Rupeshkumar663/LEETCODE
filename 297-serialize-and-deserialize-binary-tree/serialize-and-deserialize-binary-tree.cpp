/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //Serialization
    void preorder(TreeNode* root,string &s){
        if(!root){
            s+="# ";
            return;
        }
         s+=to_string(root->val)+" ";
         preorder(root->left,s);
         preorder(root->right,s);
      }

    string serialize(TreeNode* root){
        string s="";
        preorder(root,s);
        return s;
    }
      //DeSerialization
     int index=0;
    TreeNode* build(vector<string>&v){
        if(v[index]=="#"){
            index++;
            return NULL;
        }
        TreeNode* node=new TreeNode(stoi(v[index++]));
        node->left=build(v);
        node->right=build(v);
        return node;
    }

    TreeNode* deserialize(string data){
        vector<string>v;
        string temp="";
        for(int i=0;i<data.length();i++){
            if(data[i]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp+=data[i];
            }
        }
        return build(v);
    }
};
