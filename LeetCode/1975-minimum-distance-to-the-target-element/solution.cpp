class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n=nums.size();
        int minDist=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                int dist=abs(i-start);
                minDist=min(minDist,dist);
            }
        }

        return minDist;
    }
};
