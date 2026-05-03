class Solution {

private:

    bool isPrime(int x){

        if(x<=1) return false;

        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }

    int reverseInt(int x){
        int rev=0;

        while(x>0){
            rev=rev*10+(x%10);
            x/=10;
        }
        return rev;
    }

public:
    int sumOfPrimesInRange(int n){

        int r=reverseInt(n);

        int start=min(n,r);
        int end=max(n,r);
        int sum=0;
        
        for(int i=start;i<=end;i++){
            if(isPrime(i)){
                sum+=i;
            }
        }
        return sum;
    }
};
