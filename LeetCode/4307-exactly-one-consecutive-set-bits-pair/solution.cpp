class Solution {
public:
    bool consecutiveSetBits(int n){
        int cnt=0;

        while(n){
            cnt+=((n & 3)==3);       // '11' at last
            n>>=1;
        }

        return cnt==1;
    }
};
