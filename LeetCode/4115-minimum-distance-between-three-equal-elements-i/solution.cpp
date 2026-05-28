class Solution {
public:
    int minimumDistance(vector<int>& nums){

        int minDist=INT_MAX;
        int n=nums.size();
        bool found=false;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[i]==nums[k]){
                        found=true;
                        int ij=abs(i-j);
                        int jk=abs(j-k);
                        int ki=abs(k-i);
                        int dist=ij+jk+ki;
                        minDist=min(minDist,dist);
                    }
                }
            }
        }

        if(!found){
            return -1;
        }
        return minDist;
    }
};
