class Solution {
public:
    bool canConstruct(string r, string m) {
        map<char,int> count;
        int n1 = r.size();
        int n2 = m.size();
        for(int i=0;i<n2;i++)
            count[m[i]]++;
        for(int i=0;i<n1;i++){
            if(count[r[i]]<=0)
                return false;
            else
                count[r[i]]--;
        }
        return true;
    }
};
