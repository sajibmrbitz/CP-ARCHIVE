class Node{
public:
    string url;
    Node* prev;
    Node* next;
    Node(string url){
        this->url=url;
        this->prev=nullptr;
        this->next=nullptr;
    }
};


class BrowserHistory{
public:
    Node* current;
    
    BrowserHistory(string homepage){
        current=new Node(homepage);
    }
    
    void visit(string url){
        Node* newNode=new Node(url);
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
    }
    
    string back(int steps){
        while(current->prev!=nullptr && steps--){
            current=current->prev;
        }
        return current->url;
    }
    
    string forward(int steps){
        while(current->next!=nullptr && steps--){
            current=current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
