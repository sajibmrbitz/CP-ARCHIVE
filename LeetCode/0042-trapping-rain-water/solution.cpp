class Solution {
public:
    int trap(vector<int> height){

        int n=height.size();
        int left=1,right=n-2,water=0;
        int lmax=height[left-1],rmax=height[right+1];
        while(left<=right){
            if(rmax<=lmax){
                water+=max(0,rmax-height[right]);
                rmax=max(rmax,height[right]);
                right--;
            }
            else{
                water+=max(0,lmax-height[left]);
                lmax=max(lmax,height[left]);
                left++;
            }
        }
        return water;   
    }
};
