class MinStack {
private:
    struct Node{
        int data;
        int minSoFar;
        Node* next;
        
        Node(int val, int minVal, Node* n){
            data=val;
            minSoFar=minVal;
            next=n;
        }
    };

    Node* head;

public:
    MinStack(){
        head=nullptr;
    }
    
    void push(int val) {
        if(head==nullptr){
            head=new Node(val,val,nullptr);
        } 
        else{
            int newMin=min(val,head->minSoFar);
            head=new Node(val,newMin,head); 
        }
    }
    
    void pop() {
        if (head!=nullptr){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    
    int top(){
        if(head==nullptr)   return INT_MAX;
        return head->data; 
    }
    
    int getMin(){
        if (head==nullptr)   return INT_MAX;
        return head->minSoFar;
    }
};
