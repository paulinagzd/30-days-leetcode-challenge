class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i = 0;
        int j = 0;
        int k = 0;
        while(j < arr2.size()) {
            while(i < arr1.size()) {
                if(arr1[i] == arr2[j]) {
                    swap(arr1[i], arr1[k++]);
                }
                i++;
            }
            j++;
            i = k;
        }
    
        // cout << k << endl;
        if(arr1[arr1.size()-1] != arr2[j-1]) {
            i = arr1.size()-1;
            j--;
            // cout << arr1[i] << " " << arr2[j] << endl;
            while(arr1[i] != arr2[j]) {
                i--;
            }
            sort(arr1.begin()+k, arr1.end()); 
        }
        return arr1;
    }
};