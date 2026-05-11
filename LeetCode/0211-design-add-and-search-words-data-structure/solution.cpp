class WordDictionary{
    unordered_map<int,vector<string>> wordMap;

public:
    WordDictionary(){
    }
    
    void addWord(string word){
        wordMap[word.length()].push_back(word);
    }
    
    bool search(string word){
        int n=word.length();
        
        if(wordMap.find(n)==wordMap.end()){
            return false;
        }
        
        for(const string& w:wordMap[n]){
            bool isMatch=true;
            for(int i=0;i<n;i++){
                if(word[i]!='.' && word[i]!=w[i]){
                    isMatch=false;
                    break;
                }
            }
            if(isMatch) return true;
        }
        
        return false;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
