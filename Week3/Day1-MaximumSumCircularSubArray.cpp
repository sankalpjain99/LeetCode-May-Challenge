class Solution {
public:

    int maxSubarraySumCircular(vector<int>& a) {
        int ans=INT_MIN;
        int n = a.size();
        bool pos=false;
        for(int i=0;i<n;i++){
            if(a[i]>0)
                pos=true;
            ans=max(ans,a[i]);
        }
        if(!pos)
            return ans;

        int sum1=0,sum2=0,tot=0,ans1=INT_MIN,ans2=INT_MAX;
        for(int i=0;i<n;i++){
            sum1+=a[i];
            sum2+=a[i];
            tot+=a[i];
            if(sum1<0)
                sum1=0;
            if(sum2>0)
                sum2=0;
            ans1=max(ans1,sum1);
            ans2=min(ans2,sum2);
        }
        return max(ans1,tot-ans2);
    }
};
