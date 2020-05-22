class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l = 0;
        int r = a.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(m%2==0){
                if(a[m]==a[m+1])
                    l=m+1;
                else
                    r=m;
            }
            else
                if(a[m]==a[m-1])
                    l=m+1;
                else
                    r=m;
        }
        return a[l];
    }
};
