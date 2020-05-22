class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> m;
        vector<int> ans;
        int n1 = s.size();
        int n2 = p.size();
        for(int i=0;i<n2;i++){
            m[p[i]]++;
        }
        int start=0;
        int match=0;
        for(int i=0;i<n1;i++){
            if(m.find(s[i])!=m.end()){
                m[s[i]]--;
                if(m[s[i]]==0)
                    match++;
            }
            if(match==m.size()){
                ans.push_back(start);
            }
            if(i>=n2-1){
                char left = s[start++];
                if(m.find(left)!=m.end()){
                    if(m[left]==0)
                        match--;
                    m[left]++;
                }
            }
        }
        return ans;
    }
};
