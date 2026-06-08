class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        
        int count=0;
        for(long long factor=1;factor<=n;factor*=10){
            long long higherDigits=n/(factor*10);
            long long currentDigit=(n/factor)%10;
            long long lowerDigits=n%factor;

            if (currentDigit==0){
                count+=higherDigits*factor;
            } 
            else if(currentDigit==1){
                count+=higherDigits*factor+lowerDigits+1;
            } 
            else{
                count+=(higherDigits+1)*factor;
            }
        }
        
        return count;
    }
};
