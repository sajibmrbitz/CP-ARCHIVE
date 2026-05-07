class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        string LCP="";
        if (strs.empty()) return LCP;
        
        sort(strs.begin(),strs.end());
        string firstWord=strs[0];
        string lastWord=strs[strs.size()-1];
        
        for(int i=0;i<min(firstWord.length(),lastWord.length());i++){
            if(firstWord[i]==lastWord[i]){
                LCP+=firstWord[i];
            }
            else{
                break;
            }
        }
        
        return LCP;
    }
};
