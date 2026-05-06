class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> wordBox;
        
        for(string original:strs){
            string key=original;
            sort(key.begin(),key.end());
            
            wordBox[key].push_back(original);
        }
        
        vector<vector<string>> ans;
        
        for (auto it:wordBox){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
