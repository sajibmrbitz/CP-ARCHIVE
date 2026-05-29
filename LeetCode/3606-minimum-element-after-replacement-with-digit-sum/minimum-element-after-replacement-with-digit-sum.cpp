class Solution {
public:
    int minElement(vector<int>& nums) {

        int n=nums.size();
        int minElem=INT_MAX;

        for(int i=0;i<n;i++){
            int num=nums[i];
            int sum=0;
            while(num){
                int d=num%10;
                sum+=d;
                num/=10;
            }
            minElem=min(minElem,sum);
        }

        return minElem;
    }
};