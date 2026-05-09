class Solution{
public:
    int minFlips(string s){
        
        int n=s.size();
        int ones=0;
        for(char c:s){
            if(c=='1') ones++;
        }
        
        int ans=min(ones,n-ones);    // zeros=n-ones
        ans=min(ans,max(0,ones-1));
        
        if(n>=2){
            int costEnds=(s[0]=='0')+(s[n-1]=='0');
            int midOnes=ones-(s[0]=='1')-(s[n-1]=='1');
            ans=min(ans,costEnds+midOnes);
        }
        return ans;
    }
};
