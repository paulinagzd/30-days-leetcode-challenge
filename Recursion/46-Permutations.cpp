class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, res, 0);
        return res;
    }
    
    void helper(vector<int> &nums, vector<vector<int>> &res, int i) {
        if(i == int(nums.size())) {
            res.push_back(nums);
            return;
        } else {
            for(int j = i; j < int(nums.size()); ++j) {
                swap(nums[j], nums[i]); // switch
                helper(nums, res, i + 1);
                swap(nums[j], nums[i]); // reset
            }
        }
    }
};