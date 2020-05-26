class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size();
        if(n==1)
            return 0;
        unordered_map<int,int> m;
        m[0]=-1;
        int curr=0,ans=0;
        for(int i=0;i<n;i++){
            curr += (a[i]?1:-1);
            if(!curr)
                ans = i+1;
            else if(m.find(curr)!=m.end())
                ans = max(ans,i-m[curr]);
            else
                m[curr] = i;
        }
        return ans;
    }
};