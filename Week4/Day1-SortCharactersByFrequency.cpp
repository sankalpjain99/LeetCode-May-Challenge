class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i: s) {
            m[i]++;
        }
        vector<pair<char, int>> v;
        for(auto i: m) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), [&](pair<char, int> a, pair<char, int> b) -> bool {
           if(a.second == b.second) {
               return a.first < b.second;
           }
           return a.second > b.second;
        });
        string x;
        for(auto i: v) {
            for(int j=0;j<i.second;j++) {
                x += i.first;
            }
        }
        return x;
    }
};
