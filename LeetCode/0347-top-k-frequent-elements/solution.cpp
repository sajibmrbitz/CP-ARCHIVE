class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        
        unordered_map<int, int> counts;
        for(int num:nums){
            counts[num]++;
        }
        
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        
        for(auto box:counts){
            int number=box.first;
            int freq=box.second;
            
            buckets[freq].push_back(number); 
        }
        
        vector<int> finalResult;
        
        for(int i=n;i>=0;i--){
            if(buckets[i].size()>0){
                for(int num:buckets[i]){
                    finalResult.push_back(num);
                    
                    if(finalResult.size()==k){
                        return finalResult;
                    }
                }
            }
        }
        
        return finalResult;
    }
};
