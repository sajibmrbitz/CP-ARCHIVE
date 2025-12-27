class Solution {
public:
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=nullptr;
        }
    };

    class MyStack{
    private:
        Node* head; 
    public:
        MyStack(){ 
            head=nullptr; 
        }

        void push(int val){
            Node* newNode=new Node(val);
            newNode->next=head; 
            head=newNode;     
        }

        int pop(){
            if (head==nullptr) return 0; 
            Node* temp=head;
            int val=temp->data;
            head=head->next;
            delete temp;     
            return val;
        }

        int top(){
            if(head==nullptr) return 0;
            return head->data;
        }
    };

    int evalRPN(vector<string>& tokens){
        MyStack st;

        for(string& s:tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int b=st.pop();
                int a=st.pop();
                
                if(s=="+") st.push(a+b);
                else if(s=="-") st.push(a-b);
                else if(s=="*") st.push(a*b);
                else if(s=="/") st.push(a/b);
            } 
            else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
