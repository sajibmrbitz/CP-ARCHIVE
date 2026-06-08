class Solution {
public:
    long long getTrailingZeroes(long long x){
        long long zeroes=0;
        while(x>0){
            zeroes+=x/5;
            x/=5;
        }
        return zeroes;
    }
    
    int preimageSizeFZF(int k){
        long long left=0;
        long long right=5LL*k; 
        
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long zeroes=getTrailingZeroes(mid);
            
            if(zeroes==k){
                return 5;
            }
            else if(zeroes<k){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        
        return 0;
    }
};
