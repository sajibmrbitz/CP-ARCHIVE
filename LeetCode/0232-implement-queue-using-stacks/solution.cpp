class Node {
public:
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
    int size;
public:
    MyStack(){
        head=nullptr;
        size=0;
    }

    void push(int x){
        Node* newNode=new Node(x);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void pop(){
        if (head==nullptr) return;
        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
    }

    int top(){
        if(head==nullptr) return -1;
        return head->data;
    }

    bool empty(){
        return head==nullptr;
    }
};

class MyQueue{
private:
    MyStack input;
    MyStack output;
public:
    MyQueue(){
        
    }
    
    void push(int x){
        input.push(x);
    }
    
    int pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int res=output.top();
        output.pop();
        return res;
    }
    
    int peek(){     // amortized O(1)
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty(){
        return (input.empty() && output.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
