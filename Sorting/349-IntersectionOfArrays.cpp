class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        vector<int> res;
        
        for(int i : nums1) {
            m1[i] += 1;
        }
        
        for(int j : nums2) {
            if(m1.count(j)) {
                res.push_back(j);
                m1.erase(j);
            }
        }
        return res;
    }
};