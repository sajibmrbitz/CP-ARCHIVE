class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;

        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                bool found=false;
                for(char c:temp){
                    if(c==s[j]){
                        found=true;
                        break;
                    }
                }
                if(found) break;
                temp+=s[j];
                maxlen=max(maxlen,(int)temp.length());
            }
        }

        return maxlen;
    }
};

