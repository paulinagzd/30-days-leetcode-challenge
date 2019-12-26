class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        res.insert(res.end(), nums1.begin(), nums1.end());
        res.insert(res.end(), nums2.begin(), nums2.end());
        sort(res.begin(), res.end());
        
        return double((int(res.size()) % 2 == 0) ? (res[int(res.size()) / 2] + res[int(res.size()) / 2 - 1]) / 2.0 : res[(int(res.size())-1) / 2]);
    }
};