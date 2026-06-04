class Solution {
public:
    int maxPoints(vector<vector<int>>& points){

        int n=points.size();
        if(n<=2) return n;
        
        int max_points=0;
        
        for(int i=0;i<n;i++){
            unordered_map<string, int> slopeMap;
            int currMax=0;
            
            for(int j=i+1;j<n;j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                
                int g=gcd(dx, dy);
                dx/=g;
                dy/=g;
                
                if(dx<0 || (dx==0 && dy<0)){    // fix up-down slope
                    dx*=-1;
                    dy*=-1;
                }

                string slope=to_string(dx)+"_"+to_string(dy);
                
                slopeMap[slope]++;
                currMax=max(currMax,slopeMap[slope]);
            }
            max_points=max(max_points,currMax+1);
        }
        
        return max_points;
    }
};
