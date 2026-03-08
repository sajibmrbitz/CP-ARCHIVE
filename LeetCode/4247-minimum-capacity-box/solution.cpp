class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIdx=-1;
        int minUsable=1e9;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && capacity[i]<minUsable){
                minIdx=i;
                minUsable=capacity[i];
            }
        }
        
        return minIdx;
    }
};
