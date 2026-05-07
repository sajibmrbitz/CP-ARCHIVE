class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> numberSet(nums.begin(),nums.end());
        
        int longestStreak=0;
        
        for(int num:numberSet){
            if (numberSet.count(num-1)==0){
                int currentNumber=num;
                int currentStreak=1;
                
                while (numberSet.count(currentNumber+1)>0){
                    currentNumber+=1;
                    currentStreak+=1;
                }
                
                longestStreak=max(longestStreak,currentStreak);
            }
        }
        
        return longestStreak;
    }
};

