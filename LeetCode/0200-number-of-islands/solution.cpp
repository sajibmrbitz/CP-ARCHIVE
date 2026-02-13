class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()){
            return;
        }

        if(grid[r][c]=='0'){
            return;
        }

        grid[r][c]='0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int row=grid.size();
        int col=grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j);      //reset adjacent '1's
                }
            }
        }

        return islands;
    }
};
