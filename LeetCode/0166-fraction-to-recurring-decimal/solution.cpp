class Solution {
public:
    string fractionToDecimal(int numerator, int denominator){
        if(numerator==0) return "0";
        
        string result="";
        if((numerator<0)^(denominator<0)){
            result+="-";
        }
        
        long long num=abs((long long)numerator);
        long long den=abs((long long)denominator);
        
        result+=to_string(num/den);
        long long rem=num%den;
        
        if(rem==0) return result;
        result+=".";
        
        unordered_map<long long, int> remMap;
        
        while(rem!=0){
            if(remMap.find(rem)!=remMap.end()){
                result.insert(remMap[rem],"(");
                result+=")";                  
                break;
            }
            
            remMap[rem]=result.length();
            rem*=10;
            result+=to_string(rem/den);
            rem%=den;
        }
        
        return result;
    }
};
