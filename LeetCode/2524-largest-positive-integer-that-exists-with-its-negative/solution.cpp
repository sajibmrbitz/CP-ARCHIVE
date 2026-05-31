class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int n=nums.size();
        int ans=-1,candidate;
        unordered_map<int, int> mp;

        for(int x:nums){
            if(mp.count(-x)){
                candidate=max(x, abs(x));
                ans=max(ans,candidate);
            }
            mp[x]+=1;
        }

        return ans;
    }
};
