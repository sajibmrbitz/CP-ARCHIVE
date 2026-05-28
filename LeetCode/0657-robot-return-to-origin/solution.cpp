class Solution {
public:
    bool judgeCircle(string moves) {
        
        int Ucount=count(moves.begin(),moves.end(),'U');
        int Dcount=count(moves.begin(),moves.end(),'D');
        int Lcount=count(moves.begin(),moves.end(),'L');
        int Rcount=count(moves.begin(),moves.end(),'R');

        return (Lcount==Rcount && Ucount==Dcount);
    }
};
