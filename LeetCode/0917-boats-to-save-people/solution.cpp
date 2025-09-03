class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int lightest=0,heaviest=n-1,boats=0;
        while(lightest<heaviest){
            if(people[heaviest]+people[lightest]>limit){
                boats++;
                heaviest--;
            }
            else{
                boats++;
                lightest++;
                heaviest--;
            }
        }
        if(lightest==heaviest)  boats++;

        return boats;
    }

};
