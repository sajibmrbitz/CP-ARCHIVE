class Solution{
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }

    string toGoatLatin(string sentence){

        stringstream ss(sentence);
        string word;
        string ans;
        int index=1;

        while(ss>>word){

            if(isVowel(word[0])){
                word+="ma";
            }
            else{
                word=word.substr(1)+word[0]+"ma";
            }

            word+=string(index,'a');

            if(!ans.empty())
                ans+=" ";

            ans+=word;
            index++;
        }

        return ans;
    }
};
