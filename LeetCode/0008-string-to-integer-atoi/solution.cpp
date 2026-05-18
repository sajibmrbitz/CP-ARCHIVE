class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        int n=s.size();
        bool isNegative=false;
        bool digitFound=false;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(digitFound){
                    break;
                }
                continue;
            }
            else if(s[i]=='+'){
                if(digitFound){
                    break;
                }
                digitFound=true;
                continue;
            }
            else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                break;
            }
            else if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
                digitFound=true;

                if(num>INT_MAX){
                    if(isNegative){
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
            }
            else if(s[i]=='-'){
                if(digitFound){
                    break;
                }
                isNegative=true;
                digitFound=true;
            }
            else if(s[i]<48 || s[i]>57){
                break;
            }
        }

        if(isNegative){
            num=num*(-1);
        }

        return num;
    }
};
