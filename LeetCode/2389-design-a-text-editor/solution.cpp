class TextEditor {
public:
    string left;
    string right;

    TextEditor() {
        
    }
    
    void addText(string text) {
        left+=text;          
    }
    
    int deleteText(int k) {
        int count=0;
        while(k-- && !left.empty()){
            left.pop_back();
            count++;
        }
        return count;
    }

    string getleftstring(){      
        if(left.size()<=10){
            return left;
        }

        return left.substr(left.size()-10,10);
    }
    
    string cursorLeft(int k){
        while(k-- && !left.empty()){
            char c=left.back();
            left.pop_back();
            right.push_back(c);
        }
        return getleftstring();
    }
    
    string cursorRight(int k){  
        while(k-- && !right.empty()){
            char c=right.back();
            right.pop_back();
            left.push_back(c);
        }
        return getleftstring();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
