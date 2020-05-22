// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int

class Solution {
public:
    int firstBadVersion(int n) {
        ll i=1,j=n;
        int ans=n;
        while(i<j){
            ll mid = i+(j-i)/2;
            if(isBadVersion(mid)){
                ans=mid;
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};
