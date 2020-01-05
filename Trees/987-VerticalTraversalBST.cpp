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
    map<int, priority_queue<pair<int,int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> v;
        dfs(root, 0, 0);
        
        for(auto n : m) {
            priority_queue<pair<int, int>> q = n.second;
            map<int, vector<int>> temp;
            while(!q.empty()) {
                pair<int, int> top = q.top();
                temp[top.first].push_back(top.second);
                q.pop();
            }
            map<int,vector<int>>::reverse_iterator rit;
            for (rit=temp.rbegin(); rit!=temp.rend(); ++rit) {
                vector<int> now = rit->second;
                if(now.size() > 1) sort(now.begin(), now.end());
                v.insert(v.end(), now.begin(), now.end());
            }
            res.push_back(v);
            v.clear();
        }
        return res;
        }
    
    void dfs(TreeNode* root, int x, int y) {
        if(!root) return;
        dfs(root->left, x-1, y-1);
        dfs(root->right, x+1, y-1);
        m[x].push(make_pair(y, root->val));
    }
};