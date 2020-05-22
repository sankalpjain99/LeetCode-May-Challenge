class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> m;
        int n1 = s2.size();
        int n2 = s1.size();
        for(int i=0;i<n2;i++)
            m[s1[i]]++;
        int match=0;
        int start=0;
        for(int i=0;i<n1;i++){
            if(m.find(s2[i])!=m.end()){
                m[s2[i]]--;
                if(m[s2[i]]==0){
                    match++;
                }
            }
            if(match==m.size())
                return true;
            if(i>=n2-1){
                char left = s2[start++];
                if(m.find(left)!=m.end()){
                    if(m[left]==0)
                        match--;
                    m[left]++;
                }
            }
        }
        return false;
    }
};
