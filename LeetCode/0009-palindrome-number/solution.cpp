class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) return false;

        long long rev=0;
        int copy=x;
        while(copy){
            int digit=copy%10;
            copy/=10;
            rev=rev*10+digit;
        }

        return rev==x;
    }
};
