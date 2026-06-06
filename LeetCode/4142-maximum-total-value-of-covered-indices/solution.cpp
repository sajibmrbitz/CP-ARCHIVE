class Solution {
public:
    long long maxTotal(vector<int>& nums, string s){
        int n=nums.size();
        const long long NEG=-(long long)4e18;

        vector<long long> dp(2, NEG), ndp(2, NEG);
        dp[0]=0;
        dp[1]=NEG;

        for(int i=0;i<n-1;i++){
            fill(ndp.begin(), ndp.end(),NEG);

            vector<int> nextStates;
            if(s[i+1]=='1' && i+1>0)
                nextStates={0,1};
            else
                nextStates={0};

            for(int di=0;di<2;di++){
                if(dp[di]==NEG) continue;

                for(int dn:nextStates){
                    bool covered=((s[i]=='1' && di==0) || (s[i+1]=='1' && dn==1));

                    long long add=covered?nums[i]:0;

                    ndp[dn]=max(ndp[dn], dp[di]+add);
                }
            }

            dp.swap(ndp);
        }

        long long ans=0;

        for(int dn=0;dn<2;dn++){
            if(dp[dn]==NEG) continue;

            bool covered=(s[n-1]=='1' && dn==0);
            ans=max(ans, dp[dn]+(covered?nums[n-1]:0));
        }

        return ans;
    }
};
