class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> freq;
        unordered_map<int,int> freqCount;

        for(int x:nums){
            freq[x]++;
        }

        for(auto p:freq){       // freq of freqs
            freqCount[p.second]++;
        }

        for(int x:nums){   // 1st unique freq
            if(freqCount[freq[x]]==1){
                return x;
            }
        }

        return -1;
    }
};
