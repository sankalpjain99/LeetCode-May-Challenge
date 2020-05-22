class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        float m = (float)(c[1][1]-c[0][1])/(c[1][0]-c[0][0]);
        for(int i=2;i<n;i++){
            float m1 = (float)(c[i][1]-c[i-1][1])/(c[i][0]-c[i-1][0]);
            if(m1!=m)
                return false;
        }
        return true;

    }
};
