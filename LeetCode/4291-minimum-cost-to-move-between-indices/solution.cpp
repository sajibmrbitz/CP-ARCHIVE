class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long> prefR(n,0);
        vector<long long> prefL(n,0);
        
        for(int i=0;i<n-1;i++){
            long long cost=0;
            if(i==0){
                cost=1;
            }
            else{
                long long leftDiff=(long long)nums[i]- nums[i-1];
                long long rightDiff=(long long)nums[i+1]-nums[i];

                if(rightDiff<leftDiff){
                    cost=1;
                }
                else{
                    cost=rightDiff;
                }
            }
            prefR[i+1]=prefR[i]+cost;
        }
        
        for(int i=n-1;i>0;i--){
            long long cost=0;
            if(i==n-1){
                cost=1;
            }
            else{
                long long leftDiff=(long long)nums[i]-nums[i-1];
                long long rightDiff=(long long)nums[i+1]-nums[i];
                
                if(leftDiff<=rightDiff){
                    cost=1;
                }
                else{
                    cost=leftDiff;
                }
            }
            prefL[i-1]=prefL[i]+cost;
        }

        vector<int> ans;
        for(const auto& q:queries){
            int u=q[0];
            int v=q[1];
            
            if(u<v){
                ans.push_back(prefR[v]-prefR[u]);
            }
            else if(u>v){
                ans.push_back(prefL[v]-prefL[u]);
            } 
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
