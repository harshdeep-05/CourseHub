class Solution {
public:
    int d[5]={1,0,-1,0,1};
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,int prevColor)
    {
        int m=image.size(),n=image[0].size();
        if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=prevColor)return;
        
        image[i][j]=newColor;
        for(int r=0;r<4;r++)
        {
            int x=i+d[r],y=j+d[r+1];
            dfs(image,x,y,newColor,prevColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        
        if (image[sr][sc] != newColor) dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};