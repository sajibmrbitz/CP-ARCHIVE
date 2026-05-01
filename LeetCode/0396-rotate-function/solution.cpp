class Solution {
public:
    int maxRotateFunction(vector<int>& nums){
        long long sum=0;
        long long f0=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            f0+=(long long)i*nums[i];
        }
        
        long long maxval=f0;
        long long currentf=f0;
        
        for(int j=1;j<n;j++){
            currentf=currentf+sum-(long long)n*nums[n-j];
            maxval=max(maxval,currentf);
        }
        
        return maxval;
    }
};
