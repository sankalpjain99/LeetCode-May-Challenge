class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0)
            return {0};
        vector<int> dp(num+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=num;i++){
            int x = log2(i);
            int k = pow(2,x);
            dp[i] = dp[i-k]+1;
        }
        return dp;
    }
};