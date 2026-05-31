class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());

        for(int x:nums){
            mp[x]+=1;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]!=nums[j] && mp[nums[i]]!=mp[nums[j]]){
                    return {nums[i],nums[j]};
                }
            }
        }

        return {-1,-1};
    }
};
