class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,area=0,currentarea;
        if(n==0)     return 0;
        while(l<r){
            currentarea=min(height[l],height[r])*(r-l);
            area=max(currentarea,area);
            if(height[l]<=height[r])    l++;
            else                        r--;
        }
        return area;
    }
};
