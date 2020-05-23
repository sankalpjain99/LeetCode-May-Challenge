class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n1 = A.size();
        int n2 = B.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<n1 && j<n2){
            int m1 = max(A[i][0],B[j][0]);
            int m2 = min(A[i][1],B[j][1]);
            if(m1<=m2)
                ans.push_back({m1,m2});
            if(B[j][1] > A[i][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};