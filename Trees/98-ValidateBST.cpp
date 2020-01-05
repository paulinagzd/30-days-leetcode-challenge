/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* compare = nullptr;
        return helper(root, compare);
    }
    
    bool helper(TreeNode* root, TreeNode* &compare) {
        if(!root) return true;
        
        if(!helper(root->left, compare)) return false;
        if(compare != nullptr && compare->val >= root->val) return false;
        
        compare = root;
        return helper(root->right, compare);
    }
};