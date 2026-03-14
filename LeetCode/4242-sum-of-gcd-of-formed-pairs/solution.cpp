class Solution {
public:
    long long gcdSum(vector<int>& nums){
        int n=nums.size();
        vector<int> prefixGcd(n); 

        int mxi=nums[0];
        for(int i=0;i<n;i++){
            mxi=max(mxi,nums[i]); 
            prefixGcd[i]=gcd(nums[i],mxi);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        long long ans=0;
        int lo=0,hi=n-1;
        
        while(lo<hi){
            ans+=gcd(prefixGcd[lo],prefixGcd[hi]);
            lo++; 
            hi--;
        }
        
        return ans;
    }
};
