/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        ostringstream out;
        s(root, out);
        return out.str();
    }
    
    void s(TreeNode* root, ostringstream& out) {
        if(!root) {
            out << "X "; 
        } else {
            out << root->val << " ";
            s(root->left, out);
            s(root->right, out);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return d(in);
    }
    
    TreeNode* d(istringstream& in) {
        string res;
        in >> res;
        if (res == "X")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(res));
        root->left = d(in);
        root->right = d(in);
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));