class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest){
        int pigs=0;
        int states=(minutesToTest/minutesToDie)+1;
        long long handledBucket=1;

        while(handledBucket<buckets){
            handledBucket*=states;
            pigs++;
        }
        
        return pigs;
    }
};
