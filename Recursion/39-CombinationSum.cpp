class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        helper(candidates, res, v, target, 0);
        return res;
    }
    
    void helper(vector<int> &candidates, vector<vector<int>> &res, vector<int> &v, int target, int i) {
        if(target <= 0) {
            if(target == 0) res.push_back(v);
            return;
        } else {
            for(int j = i; j < int(candidates.size()); ++j) {
                v.push_back(candidates[j]);
                helper(candidates, res, v, target - candidates[j], j);
                v.pop_back();
            }
        }
    }
};