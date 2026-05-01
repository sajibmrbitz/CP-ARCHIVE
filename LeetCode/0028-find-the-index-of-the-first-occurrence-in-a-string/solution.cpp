class Solution {        // KMP algo
private:
    void computeLPSArray(string& needle, int m, vector<int>& lps) {
        int len=0;
        lps[0]=0;
        int i=1;
        
        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle){
        int n=haystack.length();
        int m=needle.length();
        
        if(m==0) return 0;
        if(m>n) return -1; 

        vector<int> lps(m);
        computeLPSArray(needle,m,lps);
        
        int i=0;
        int j=0;
        
        while(i<n){
            if(needle[j]==haystack[i]){
                j++;
                i++;
            }
            
            if(j==m){
                return i-j;
            } 

            else if(i<n && needle[j]!=haystack[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        return -1; 
    }
};
