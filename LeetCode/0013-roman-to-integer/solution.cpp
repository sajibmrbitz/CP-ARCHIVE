class Solution {
private:
    int getValue(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

public:
    int romanToInt(string s){
        int num=0;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            int currentVal=getValue(s[i]);
            
            if(i+1<n && currentVal<getValue(s[i+1])){
                num-=currentVal;
            }
            else{
                num+=currentVal;
            }
        }
        
        return num;
    }
};
