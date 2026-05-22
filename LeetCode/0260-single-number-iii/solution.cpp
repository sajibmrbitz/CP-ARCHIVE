class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_sum=0;
        for(int num:nums){
            //xor_sum+=^num;
            xor_sum^=num;
        }

        long long alada_bit=xor_sum & (-xor_sum);
        
        int a=0,b=0;        //grouping to regenerate 2 nums
        for (int num:nums){
            if((num & alada_bit)==0){
                a^=num;
            }
            else{
                b^=num;
            }
        }
        
        return {a,b};
    }
};
