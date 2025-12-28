class Node{
public:
    int data;
    Node* next;
    Node(int new_data){
        data=new_data;
        next=nullptr;
    }
};

class myQueue{
private:
    int size;
    Node* front;
    Node* rear;

public:
    myQueue(){
        size=0;
        front=rear=nullptr;
    }

    bool isEmpty(){               
        return front==nullptr;
    }

    void enqueue(int new_data){   
        Node* node=new Node(new_data);
        if(isEmpty()){
            front=rear=node;
        } 
        else{
            rear->next=node;
            rear=node;
        }

        size++;
    }

    int dequeue(){               
        if (isEmpty()){
            return -1;
        }
        
        Node* temp=front;
        int tbd=temp->data;
        front=front->next;
        
        if(front==nullptr) rear=nullptr;
        delete temp;
        
        size--;
        return tbd;
    }

    int getFront(){                  // O(1)
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }
    
    int getSize(){
        return size;
    }
};

class MyStack {
private:
    myQueue q;
public:
    MyStack() {
        
    }
    
    void push(int x){                   // O(n), add and rotate
        q.enqueue(x);
        int qsize=q.getSize();

        for(int i=0;i<qsize-1;i++){     //rotate
            int val=q.dequeue();
            q.enqueue(val);
        }
    }
    
    int pop(){
        if(q.isEmpty())   return -1;
        return q.dequeue();
    }
    
    int top(){
        if(q.isEmpty())   return -1;
        return q.getFront();
    }
    
    bool empty() {
       return q.isEmpty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
