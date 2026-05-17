class Solution {
public:
    int countOnes(int x){
        int cnt=0;

        while(x>0){
            cnt+=(x%2);
            x/=2;
        }

        return cnt;
    }

    vector<int> countBits(int n){

        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countOnes(i));
        }

        return ans;
    }
};
