class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        map<int,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++){
            if(itr->second > n/2)
                return itr->first;
        }
        return -1;
    }
};
