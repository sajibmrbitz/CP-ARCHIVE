class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();

        long long total=0;
        for(int i=0;i<n;i++){
            total+=apple[i];
        }

        sort(capacity.begin(),capacity.end());
        int it=m-1;
        int boxes=0;
        while(total>0){
            boxes++;
            total-=capacity[it];
            it--;
        }

        return boxes;
    }
};
