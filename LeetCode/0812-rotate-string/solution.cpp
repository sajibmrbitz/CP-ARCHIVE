class Solution{
public:
    bool rotateString(string s,string goal){

        if(s.length()!=goal.length()){
            return false;
        }
        
        string SS=s+s;
        return SS.find(goal)!=string::npos;
    }
};
