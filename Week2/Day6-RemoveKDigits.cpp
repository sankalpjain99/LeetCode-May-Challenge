class Solution {
public:

    string removeKdigits(string num, int k) {
        int n = num.size();
        if(!k)
            return num;
        int i;
        for(i=0;i<n-1;i++){
            if(num[i]>num[i+1])
                break;
        }
        if(num.size())
            num.erase(i,1);
        if(num.size() && num[0]=='0')
            num.erase(0,1);
        if(!num.size())
            return "0";
        return removeKdigits(num,k-1);
    }
};
