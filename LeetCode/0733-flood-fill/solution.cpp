class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int initialColor, int newcolor){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size()){
            return;
        }
        if(image[r][c]!=initialColor){
            return;
        }

        image[r][c]=newcolor;
        dfs(image,r+1,c,initialColor,newcolor);
        dfs(image,r-1,c,initialColor,newcolor);
        dfs(image,r,c+1,initialColor,newcolor);
        dfs(image,r,c-1,initialColor,newcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        if(initialColor!=color){
            dfs(image,sr,sc,initialColor,color);
        }
        return image;
    }
};
