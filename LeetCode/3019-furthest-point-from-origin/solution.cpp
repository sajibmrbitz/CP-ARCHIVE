class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int Lcount=count(moves.begin(),moves.end(),'L');
        int Rcount=count(moves.begin(),moves.end(),'R');
        int spaceCount=count(moves.begin(),moves.end(),'_');

        return abs(Lcount-Rcount)+spaceCount;
    }
};
