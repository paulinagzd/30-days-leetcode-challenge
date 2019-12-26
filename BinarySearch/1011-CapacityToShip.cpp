class Solution {
    public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = INT_MIN;
        int right = 0;
        
        for(int i : weights) {
            left = max(left, i);
            right += left;
        }
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            int curr = 0;
            int d = curr;
            for(int j : weights) {
                if(curr + j > mid) {
                    d++;
                    curr = 0;
                }
                
                curr += j;
            }
            
            (++d > D) ? left = mid + 1 : right = mid;
        }
        return left;
    }
};