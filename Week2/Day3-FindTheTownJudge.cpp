class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int possible[N+1];
        memset(possible,0,sizeof(possible));
        for(int i=0;i<trust.size();i++){
            possible[trust[i][1]]++;
        }
        for(int i=0;i<trust.size();i++){
            possible[trust[i][0]]--;
        }
        for(int i=1;i<=N;i++){
            if(possible[i]==N-1)
                return i;
        }
        return -1;
    }
};
