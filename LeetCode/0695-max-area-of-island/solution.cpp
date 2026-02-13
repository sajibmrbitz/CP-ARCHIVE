class Solution {
public:

    void dfs(vector<vector<int>>& grid, int r, int c, int& area){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()){
            return;
        }

        if(grid[r][c]==0){
            return;
        }

        area++;
        grid[r][c]=0;
        dfs(grid,r+1,c,area);
        dfs(grid,r-1,c,area);
        dfs(grid,r,c+1,area);
        dfs(grid,r,c-1,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int row=grid.size();
        int col=grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid,i,j,area);      //count adjacent '1's
                    maxarea=max(area,maxarea);
                }
            }
        }

        return maxarea;
    }
};
