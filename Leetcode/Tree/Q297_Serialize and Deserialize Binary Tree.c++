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
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node){
                ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }else{
                ans += "# ";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        stringstream ss(data);
        string tmp;
        ss >> tmp;
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ss >> tmp;
            if(tmp != "#"){
                node->left = new TreeNode(stoi(tmp));
                q.push(node->left);
            }
            ss >> tmp;
            if(tmp != "#"){
                node->right = new TreeNode(stoi(tmp));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
