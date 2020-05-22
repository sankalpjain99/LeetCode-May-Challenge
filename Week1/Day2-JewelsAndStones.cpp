class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> m;
        int n1 = J.size();
        int n2 = S.size();
        for(int i=0;i<n2;i++)
            m[S[i]]++;
        int ans=0;
        for(int i=0;i<n1;i++)
            ans+=m[J[i]];
        return ans;
    }
};
