class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // if(A.size() == 3) return 1;
        
        int i = 0, j = A.size()-1;
        
        while(i < j) {
            if(A[i] > A[j]) {
                j--;   
            } else if(A[i] < A[j]) {   
                i++;
            } else {
                i++;
                j--;
            }
        }
        return i;
    }
};