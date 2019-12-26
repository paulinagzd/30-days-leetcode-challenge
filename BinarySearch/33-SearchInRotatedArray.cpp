class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = int(nums.size())-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            // check if it's rotated, then in which half should the target be
            if(nums[mid] <= nums[right]) {
                ((target <= nums[right] && target > nums[mid]) ? left = mid + 1 : right = mid - 1);
            } else {
                ((target > nums[mid] || target <= nums[right]) ? left = mid + 1 : right = mid - 1);
            }
            cout << left << " " << right << endl;
        }
        return -1;
    }
};