class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerLast(26,-1);
        vector<int> capital1st(26,-1);

        for(int i=0;i<word.length();i++){
            char c=word[i];
            
            if(c>='a' && c<='z'){
                lowerLast[c-'a']=i;
            } 
            else if(c>='A' && c<='Z'){
                if(capital1st[c-'A']==-1){
                    capital1st[c-'A']=i;
                }
            }
        }

        int special=0;

        for(int i=0;i<26;i++){
            if(lowerLast[i]!=-1 && capital1st[i]!=-1 && lowerLast[i]<capital1st[i]){
                special++;
            }
        }

        return special;
    }
};
