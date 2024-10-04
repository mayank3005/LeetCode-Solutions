#define vvi vector<vector<int>>

class Solution {
public:
    int dd[5]={0,1,0,-1,0};
    void dfs(vvi &image,int sr,int sc,int orig,int color){
        int m=image.size(),n=image[0].size();
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int r=sr+dd[i],c=sc+dd[i+1];
            if(r<0 or c<0 or r>=m or c>=n or image[r][c]!=orig) continue;
            dfs(image,r,c,orig,color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig=image[sr][sc];
        int m=image.size(),n=image[0].size();
        if(orig==color) return image;
        
        dfs(image,sr,sc,orig,color);
        return image;
    }
};