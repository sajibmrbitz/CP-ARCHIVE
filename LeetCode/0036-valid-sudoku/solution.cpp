class Solution {
private:
    
    bool isValidBox(vector<vector<char>>& board, int startRow, int startCol) {
        bool seen[9]={false};
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                char c=board[startRow+i][startCol+j];
                if(c=='.') continue;
                
                int val=c-'1';
                if(seen[val]) return false;
                seen[val]=true;
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            bool rowSeen[9]={false};
            bool colSeen[9]={false};
            
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int rVal=board[i][j]-'1';
                    if (rowSeen[rVal]) return false;
                    rowSeen[rVal]=true;
                }
                
                if(board[j][i]!='.'){
                    int cVal=board[j][i]-'1';
                    if(colSeen[cVal]) return false;
                    colSeen[cVal]=true;
                }
            }
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(!isValidBox(board,i,j)){
                    return false;
                }
            }
        }
        
        return true;
    }
};

