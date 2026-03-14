class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2){
        
        unordered_map<int,int> freq;
        for(int x:nums1) freq[x]++;
        for(int x:nums2) freq[x]++;
        
        for(auto& p:freq){
            if(p.second%2!=0){
                return -1;
            }
        }
            
        unordered_map<int,int> target;
        for(auto& p:freq){
            target[p.first]=p.second/2;
        }
            
        unordered_map<int,int> cnt1;
        for(int x:nums1){
            cnt1[x]++;
        }
        int cost=0;
        for(auto& p:cnt1){
            int need=target[p.first];
            if(p.second>need){
                cost+=p.second-need;
            }
        }
        return cost;
    }
};
