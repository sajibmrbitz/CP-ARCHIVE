class Solution {
public:
    int climbStairs(int n){         // fibonacci concept : 1,2,3...

        if(n<=2){
            return n;
        }

        int prev1=2;                // (n-1)th step
        int prev2=1;                // (n-2)th step
        int curr=0;

        for(int i=3;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }

        return curr;
        
    }
};
