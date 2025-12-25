class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int sum=0;
        int xorsum1=0,xorsum2=0;
        for(int i=0;i<arr1.size();i++){
            xorsum1^=arr1[i];
        }
        for(int i=0;i<arr2.size();i++){
            xorsum2^=arr2[i];
        }
        sum=(xorsum1 & xorsum2);
        return sum;
    }
};
