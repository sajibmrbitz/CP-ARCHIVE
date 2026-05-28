class Solution {
public:
    vector<int> separateDigits(vector<int>& nums){

        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            vector<int> vec;
            int num=nums[i];
            while(num){
                int digit=num%10;
                vec.push_back(digit);
                num/=10;
            }
            reverse(vec.begin(),vec.end());
            ans.insert(ans.end(),vec.begin(),vec.end());
        }

        return ans;
    }
};
