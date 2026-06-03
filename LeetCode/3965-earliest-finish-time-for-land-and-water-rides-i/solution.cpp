class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int m=landStartTime.size();
        int n=waterStartTime.size();
        int minimum=INT_MAX;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int landFinish=landStartTime[i]+landDuration[i];
                int waterStart=max(landFinish,waterStartTime[j]);
                minimum=min(minimum, waterStart+waterDuration[j]);

                int waterFinish=waterStartTime[j]+waterDuration[j];
                int landStart=max(waterFinish, landStartTime[i]);
                minimum=min(minimum, landStart+landDuration[i]);
            }
        }

        return minimum==INT_MAX?-1:minimum;
    }
};
