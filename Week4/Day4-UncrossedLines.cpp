class Solution {
public:
        
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n1 = A.size();
        int n2 = B.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(A[i-1]==B[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};