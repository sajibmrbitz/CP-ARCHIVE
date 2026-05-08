class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxidx=0;
        int maxval=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxval){
                maxidx=i;
                maxval=nums[i];
            }
        }
        long long ascendSum=0,descendSum=0;

        for(int i=0;i<nums.size();i++){
            if(i<maxidx){
                ascendSum+=nums[i];
            }
            else if(i>maxidx){
                descendSum+=nums[i];
            }
        }

        if(ascendSum>descendSum){
            return 0;
        }
        else if(descendSum>ascendSum){
            return 1;
        }
        else return -1;
    }
};
