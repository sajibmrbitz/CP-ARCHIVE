class Solution {
    int rev(int n){

        int r=0;

        while(n){
            int d=n%10;
            r=r*10+d;
            n/=10;
        }

        return r;
    }
public:
    int mirrorDistance(int n) {
        int ulta=rev(n);
        return abs(n-ulta);
    }
};
