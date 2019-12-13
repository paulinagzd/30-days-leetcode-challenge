class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int j = 1;
        int cont = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(j < nums.size()) {
                if(nums[j] < nums[i]) cont++;
                j++;
            }
            j = i+1;
            res.push_back(cont);
            cont = 0;
        }
        return res;
    }
};