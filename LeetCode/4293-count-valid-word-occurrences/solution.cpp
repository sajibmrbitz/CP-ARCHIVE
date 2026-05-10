class Solution{
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries){
        
        string s;
        int totalLen=0;
        
        for(const string& chunk:chunks){
            totalLen+=chunk.length();
        }
        s.reserve(totalLen);
        for(const string& chunk:chunks){
            s+=chunk;
        }

        unordered_map<string, int> wordCount;
        string curr="";
        int n=s.length();

        auto smaller=[](char c){
            return c>='a' && c<='z';
        };

        for(int i=0;i<n;i++){
            if(smaller(s[i])){
                curr+=s[i];
            }
            else if(s[i]=='-' && i>0 &&i<n-1 && smaller(s[i-1]) && smaller(s[i+1])){
                curr+=s[i];
            }
            else{
                if(!curr.empty()){
                    wordCount[curr]++;
                    curr="";
                }
            }
        }

        if(!curr.empty()){
            wordCount[curr]++;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(const string& q:queries){
            ans.push_back(wordCount[q]);
        }

        return ans;
    }
};
