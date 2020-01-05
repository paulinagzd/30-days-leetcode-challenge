class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, v, 0, res);
        return res;    
    }
    
    void helper(vector<int> &nums, vector<int> &v, int i, vector<vector<int>> &res) {
        res.push_back(v);
        for(int j = i; j < int(nums.size()); ++j) {
            v.push_back(nums[j]);
            helper(nums, v, j + 1, res);
            v.pop_back();
        }
    }
};