class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);

        for(const auto& trip:trips){
            int num=trip[0],from=trip[1],to=trip[2];
            diff[from]+=num;
            diff[to]-=num;
        }

        int current=0;
        for(int i=0;i<=1000;i++){
            current+=diff[i];
            if(current>capacity) return false;
        }

        return true;
    }
};

