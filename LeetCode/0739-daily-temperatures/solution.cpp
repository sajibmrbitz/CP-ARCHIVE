class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {  // monotonic stack->O(N)
        int n=temperatures.size();
        vector<int> ans(n,0);
        vector<int> stack(n);

        for(int i=0;i<n;i++){
            while(!stack.empty() && temperatures[i]>temperatures[stack.back()]){
                int prevIdx=stack.back();
                stack.pop_back();

                ans[prevIdx]=i-prevIdx;
            }

            stack.push_back(i);
        }

        return ans;
    }
};
