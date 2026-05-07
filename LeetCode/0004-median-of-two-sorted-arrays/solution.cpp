class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged=nums1;
        merged.insert(merged.end(), nums2. begin(), nums2.end());
        
        sort(merged.begin(), merged.end());
        double median=0;
        int n=merged.size();            
        if(n%2==1){
            median=merged[(n/2)];
        }
        else{
            median=(merged[(n/2)-1] + merged[(n/2)])/2.0;
        }
        
        return median;
    }
};
