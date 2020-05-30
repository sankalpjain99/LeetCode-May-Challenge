class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        multimap<double,vector<int>> m;
        int n = points.size();
        for(int i=0;i<n;i++){
            double d = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            m.insert(pair<double,vector<int>> (d,points[i]));
        }
        multimap<double,vector<int>>::iterator itr=m.begin();
        while(K--){
            ans.push_back(itr->second);
            itr++;
        }
        return ans;
    }
};