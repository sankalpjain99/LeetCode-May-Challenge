class Solution {
public:

    void fill(int i,int j,int m,int n,vector<vector<int>>& a,int curr,int flood,bool** vis){
        if(i<0 || i>=m || j<0 || j>=n || a[i][j]!=curr || vis[i][j])
            return;

        a[i][j]=flood;
        vis[i][j]=true;
        fill(i-1,j,m,n,a,curr,flood,vis);
        fill(i+1,j,m,n,a,curr,flood,vis);
        fill(i,j-1,m,n,a,curr,flood,vis);
        fill(i,j+1,m,n,a,curr,flood,vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curr = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        bool** vis = new bool*[m];
        for(int i=0;i<m;i++)
            vis[i]= new bool[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        fill(sr,sc,m,n,image,curr,newColor,vis);
        return image;
    }

};
