class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();

        queue<vector<int>> q;
        int freshcount=0;

        //insert rottens into q and count fresh ones
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                else if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }

        if(freshcount==0){
            return 0;
        }

        int finaltime=0;
        while(!q.empty()){
            vector<int> curr=q.front();
            q.pop();

            int r=curr[0];
            int c=curr[1];
            int t=curr[2];
            finaltime=max(finaltime,t);

            if(r-1>=0 && grid[r-1][c]==1){      //up
                grid[r-1][c]=2;
                freshcount--;
                q.push({r-1,c,t+1});
            }   
            if(r+1<row && grid[r+1][c]==1){      //down
                grid[r+1][c]=2;
                freshcount--;
                q.push({r+1,c,t+1});
            }  
            if(c-1>=0 && grid[r][c-1]==1){      //left
                grid[r][c-1]=2;
                freshcount--;
                q.push({r,c-1,t+1});
            }
            if(c+1<col && grid[r][c+1]==1){      //right
                grid[r][c+1]=2;
                freshcount--;
                q.push({r,c+1,t+1});
            }
        }
        if(freshcount>0){                       //if still fressh,impossible
            return -1;
        }

        return finaltime;

    }
};
