class Solution {
public:

    class myStack{
    private:
        char* arr;
        int top;
        int capacity;
    public:
        myStack(int n){
            capacity=n;
            arr= new char[capacity];
            top=-1;
        }
        void push(char c){
            arr[++top]=c;
        }
        void pop(){
            if(top>=0)  top--;
        }
        char peek(){
            if(top==-1) return '\0';
            return arr[top];
        }
        bool isEmpty(){
            return top==-1;
        }
        ~myStack(){
            delete[] arr;
        }
    };
    bool isValid(string s){
        int n=s.length();
        myStack st(n);

        for(char c:s){
            if(c=='(' || c=='{' || c=='['){ 
                st.push(c);
            }
            else{
                if(st.isEmpty())    return false;
                char topchar=st.peek();
                if((c==')' && topchar=='(') ||
                   (c=='}' && topchar=='{') ||
                   (c==']' && topchar=='[')
                )   st.pop();
                else{
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
};
