class Solution {
public:
    int maxFixedPoints(vector<int>& nums){
        vector<pair<int,int>> okPairs;
        
        for(int i=0;i<nums.size();i++){
            int v=nums[i];
            if(v<=i){
                okPairs.push_back({v,i-v});
            }
        }
        
        sort(okPairs.begin(),okPairs.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            if(a.first!=b.first) 
                return a.first<b.first;
            return a.second>b.second;
        });
        
        vector<int> dp;
        for(const auto& p:okPairs){
            int d=p.second;
            
            auto it=upper_bound(dp.begin(),dp.end(),d);
            
            if(it==dp.end()){
                dp.push_back(d);
            }
            else{
                *it=d;
            }
        }
        return dp.size();
    }
};
