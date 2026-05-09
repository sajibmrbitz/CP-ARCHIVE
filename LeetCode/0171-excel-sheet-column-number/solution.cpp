class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int num=0;
        for(int i=0;i<n;i++){
            num=num*26+(int)(columnTitle[i]+1-'A');
        }
        
        return num;
    }
};
