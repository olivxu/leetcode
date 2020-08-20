class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // special case 1: n is empty
        if(!n)
            return;
        
        // special case 2: m is empty and n is not empty
        if(!m) {
            for(int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        
        // normal case:
        int m_index = m - 1;
        int n_index = n - 1;
        
        for(int i = m + n -1; i >= 0; i--) {
            if(m_index >= 0 && n_index >= 0){
                if(nums1[m_index] >= nums2[n_index]) {
                    nums1[i] = nums1[m_index];
                    m_index--;
                }
                else {
                    nums1[i] = nums2[n_index];
                    n_index--;
                }
            }
            else if(n_index >= 0) {
                nums1[i] = nums2[n_index];
                n_index--;
            }
        }
    }
};