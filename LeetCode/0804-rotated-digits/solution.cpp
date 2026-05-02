class Solution {
public:
    int rotatedDigits(int n){    // n<10^4
        int count=0;
        
        for(int i=1;i<=n;i++){
            int num=i;
            bool isValid=true;
            bool hasRotaryDigit=false;
            
            while(num>0){
                int digit=num%10;
                
                if(digit==3 || digit==4 || digit==7){
                    isValid=false;
                    break;
                }
                
                if(digit==2 || digit==5 || digit==6 || digit==9){
                    hasRotaryDigit=true;
                }
                
                num/=10;
            }
            
            if(isValid && hasRotaryDigit){
                count++;
            }
        }
        
        return count;
    }
};
