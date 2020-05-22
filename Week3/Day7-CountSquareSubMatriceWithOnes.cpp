class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n1 = matrix.size();
        int n2 = matrix[0].size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(matrix[i-1][j-1]){
                    if(dp[i-1][j] && dp[i][j-1])
                        dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    else
                        dp[i][j]=1;
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
