class Solution {
public:
    bool isGood(vector<int>& nums){
        int n=nums.size()-1;
        vector<int> freq(n+1,0);

        for(int i=0;i<=n;i++){

            if(nums[i]>n || nums[i]<1){
                return false;
            }

            freq[nums[i]]++;
        }

        for(int i=1;i<n;i++){
            if(freq[i]!=1){
                return false;
            }
        }

        if(freq[n]!=2){
            return false;
        }

        return true;
    }
};
