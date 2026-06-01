class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n=cost.size();
        sort(cost.rbegin(), cost.rend());
        int minimum=0;

        for(int i=0;i<n;i++){
            if((i+1)%3==0){
                continue;
            }
            minimum+=cost[i];
        }

        return minimum;
    }
};
