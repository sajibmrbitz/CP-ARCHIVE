class Solution {
public:
    bool validDigit(int n, int x) {
        int firstDigit=n;
        while(firstDigit>=10){
            firstDigit/=10;
        }


        bool occur=false;
        while(n){
            int d=n%10;
            if(d==x){
                occur=true;
                break;
            }
            n/=10;
        }

        if(occur==true && firstDigit!=x){
            return true;
        }
        return false;
    }
};
