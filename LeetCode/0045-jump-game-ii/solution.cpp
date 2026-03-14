class Solution {
public:
    int jump(vector<int>& nums){
        int jumps=0,L=0,R=0;
        
        while(R<nums.size()-1){
            int farthest=0;

            for(int i=L;i<=R;i++){
                farthest=max(farthest,i+nums[i]);
            }
            
            L=R+1;
            R=farthest;
            jumps++;
        }
        return jumps;
    }
};
