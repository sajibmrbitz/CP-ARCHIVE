class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        int n=nums.size();
        vector<int> score(2,0);
        int active=0;           // initially 1st player

        for(int i=0;i<n;i++){

            //score[active]+=nums[i];
            if(nums[i]%2==1){
                active^=1;      // swap 0<->1
            }
            if(i%6==5){
                active^=1;      // swap 0<->1
            }

            score[active]+=nums[i];
 
        }

        return score[0]-score[1];
    }
};
