class Solution {
public:
    int reverse(int x){
        long long r=0;
        long long copy=(x>=0)?x:-(long long)x;
        if(copy>=(1ll<<31))   return 0;

        while(copy){
            r=r*10+copy%10;
            copy/=10;
        }
        
        if (r>INT_MAX || r<INT_MIN) return 0;
        r=(x>=0)?r:-r;
        return r;
    }
};
