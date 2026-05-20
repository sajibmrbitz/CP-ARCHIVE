class Solution {
public:
    int trailingZeroes(int n){     // only count how many 5's are there
        int trailingZeros=0;

        while(n>0){
            n/=5;
            trailingZeros+=n;
        }

        return trailingZeros;
    }
};
