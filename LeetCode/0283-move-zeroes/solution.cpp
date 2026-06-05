class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j=0;
        for(int x:nums){
            if(x!=0){
                nums[j++]=x;
            }
        }

        while(j<nums.size()){
            nums[j++]=0;
        }
    }
};
