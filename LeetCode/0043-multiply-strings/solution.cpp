class Solution {
private:
    
    vector<int> stringToInt(const string& num) {
        vector<int> res;
        for(int i=num.size()-1;i>=0;i--){
            res.push_back(num[i]-'0');
        }
        return res;
    }

    string intToString(const vector<int>& res){
        string s="";
        int i=res.size()-1;
        
        while(i>=0 && res[i]==0){
            i--;
        }
        
        if(i<0) return "0";
        
        while(i>=0){
            s.push_back(res[i]+'0');
            i--;
        }
        return s;
    }

public:
    string multiply(string num1, string num2) {
       
        if(num1=="0" || num2=="0") return "0";
        
        vector<int> n1=stringToInt(num1);
        vector<int> n2=stringToInt(num2);
        
        vector<int> res(n1.size()+n2.size(),0);

        for(int i=0;i<n1.size();i++){
            for(int j=0;j<n2.size();j++){
                int mul=n1[i]*n2[j];
                int sum=mul+res[i+j];
                
                res[i+j]=sum%10;         
                res[i+j+1]+=sum/10;
            }
        }
        
        return intToString(res);
    }
};

