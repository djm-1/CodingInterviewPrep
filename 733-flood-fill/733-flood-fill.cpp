class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int curr){
        int m=image.size();
        int n=image[0].size();
        
        if(sr>=m||sr<0||sc>=n||sc<0||image[sr][sc]!=curr||image[sr][sc]==color)
            return;
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,curr);
        dfs(image,sr,sc-1,color,curr);
        dfs(image,sr,sc+1,color,curr);
        dfs(image,sr+1,sc,color,curr);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr=image[sr][sc];
        dfs(image,sr,sc,color,curr);
        return image;
    }
};