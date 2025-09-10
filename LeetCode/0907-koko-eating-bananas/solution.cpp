class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int speed=*max_element(piles.begin(),piles.end());
        int low=1,high=speed;
        while(low<=high){
            int avg=(low+high)/2;
            long long eaten=0;
            for(auto x:piles){
                eaten+=(x+avg-1)/avg;
            }
            if(eaten<=h){
                speed=avg;
                high=avg-1;
            }
            else{
                low=avg+1;
            }
        }
        return speed;
    }
};
