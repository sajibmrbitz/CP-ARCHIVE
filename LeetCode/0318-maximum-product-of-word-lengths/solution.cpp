class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        
        vector<int> masks(n, 0);
        vector<int> lengths(n, 0);

        for(int i=0;i<n;i++){
            lengths[i]=words[i].length();
            for(char c:words[i]){
                masks[i]|=(1<<(c-'a'));
            }
        }

        int max_val=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((masks[i] & masks[j])==0){
                    max_val=max(max_val, lengths[i]*lengths[j]);
                }
            }
        }

        return max_val;
    }
};

