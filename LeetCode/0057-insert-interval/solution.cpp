class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n=intervals.size();
        
        int current=0;
        while(current<n && intervals[current][1]<newInterval[0]){
            result.push_back(intervals[current]);
            current++;
        }
        
        while(current<n && intervals[current][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[current][0]);
            newInterval[1]=max(newInterval[1], intervals[current][1]);
            current++;
        }
        result.push_back(newInterval);
        
        while(current<n){
            result.push_back(intervals[current]);
            current++;
        }
        
        return result;
    }
};
