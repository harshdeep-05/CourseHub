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

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string &s)
    {
        if(!root)
        {
            s+="N ";
            return;
        }
        
        s+=to_string(root->val)+" ";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s="";
        if(!root)return s;
        preorder(root,s);
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* solve(vector<string> &v,int &i)
    {
        if(v[i]=="N")
        {
            return NULL;
        }
        
        // int val=0,j=0,flag=1;
        // if(v[i][j]=='-1'){
        //     flag=-1;
        //     j++;
        // }
        // while(j<v[i].size())
        // {
        //     val=val*10+v[i][j]-'0';
        //     j++;
        // }
        // val*=flag;
        TreeNode* root=new TreeNode(stoi(v[i]));
        i++;
        root->left=solve(v,i);
        i++;
        root->right=solve(v,i);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        vector<string> v;
        stringstream ss(data);
        string temp;
        while(ss>>temp)
        {
            v.push_back(temp);
        }
        if(v.empty())return NULL;
        int i=0;
        return solve(v,i);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));