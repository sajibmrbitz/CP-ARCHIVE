class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target<nums[0]){
            return 0;
        }
        int idx=-1;
        int left=0;
        int right=nums.size()-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                idx=mid;
                break;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                if(nums[mid-1]<target){
                    idx=mid;
                    break;
                }
                right=mid-1;
            }
        }
        
        return (idx>=0)?idx:nums.size();
    }
};
