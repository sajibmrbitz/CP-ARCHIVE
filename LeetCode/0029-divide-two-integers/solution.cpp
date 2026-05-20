class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }

        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);

        long long count=0;

        while(a>=b){
            int shift=0;

            while(a>=(b<<(shift+1))){
                shift++;
            }

            count+=(1LL<<shift);
            a-=(b<<shift);
        }

        if((dividend<0)^(divisor<0)){
            count=-count;
        }

        return (int)count;
    }
};
