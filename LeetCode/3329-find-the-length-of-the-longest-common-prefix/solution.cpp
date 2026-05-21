class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        unordered_set<int> prefixes;

        for(auto x:arr1){
            while(x>0){
                prefixes.insert(x);
                x/=10;
            }
        }

        int ans=0;
        for(auto y:arr2){
            while(y>0){
                if(prefixes.count(y)){
                    ans=max(ans,(int)to_string(y).size());
                }
                y/=10;
            }
        }

        return ans;
    }
};
