class Solution {
private:
    vector<string> infixToPostfix(string s){
        vector<string> postfix;
        stack<char> ops;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            
            if(isdigit(s[i])){
                string num="";
                while(i<n && isdigit(s[i])){
                    num+=s[i];
                    i++;
                }
                i--;
                postfix.push_back(num);
            }
            else if(s[i]=='('){
                ops.push('(');
            }
            else if(s[i]==')'){
                while(!ops.empty() && ops.top()!='('){
                    postfix.push_back(string(1,ops.top()));
                    ops.pop();
                }
                if(!ops.empty()) ops.pop();
            }
            else if(s[i]=='+' || s[i]=='-'){
                bool isUnary=false;
                if(s[i]=='-'){
                    int j=i-1;
                    while(j>=0 && s[j]==' '){
                        j--;
                    }
                    if(j<0 || s[j]=='('){
                        isUnary=true;
                    }
                }
                
                if(isUnary){
                    postfix.push_back("0");
                }
                
                while(!ops.empty() && ops.top()!='('){
                    postfix.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        
        while(!ops.empty()){
            postfix.push_back(string(1, ops.top()));
            ops.pop();
        }
        
        return postfix;
    }

    int evaluatePostfix(vector<string>& postfix){
        stack<long long> st;
        
        for(const string& token:postfix){
            if(token=="+" || token=="-"){
                long long b=st.top();
                st.pop();
                long long a=st.top();
                st.pop();
                
                if(token=="+"){
                    st.push(a+b);
                }
                else if(token=="-"){
                    st.push(a-b);
                }
            }
            else{
                st.push(stoll(token));
            }
        }
        
        return st.top();
    }

public:
    int calculate(string s){
        vector<string> postfix=infixToPostfix(s);
        return evaluatePostfix(postfix);
    }
};
