class Solution{
public:
    long long minArraySum(vector<int>& nums){
        int maxval=0;
        for(int num:nums){
            if(num>maxval){
                maxval=num;
            }
        }
        
        vector<bool> present(maxval+1,false);
        for(int num:nums){
            present[num]=true;
        }
        
        vector<int> minDivisors(maxval+1,0);
        for(int i=1;i<=maxval;i++){
            if(present[i]){
                for(int j=i;j<=maxval;j+=i){
                    if (minDivisors[j]==0){
                        minDivisors[j]=i;
                    }
                }
            }
        }
        
        long long sum=0;
        for(int num:nums){
            sum+=minDivisors[num];
        }
        
        return sum;
    }
};
