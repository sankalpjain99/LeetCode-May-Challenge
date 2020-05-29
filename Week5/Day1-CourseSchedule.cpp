class Solution {
public:
    
    bool isCycle(int i,vector<vector<int>>& g,int n,bool vis[],bool mark[]){
        vis[i]=true;
        for(auto x:g[i]){
            if(!mark[x]){
                mark[x]=true;
                if(isCycle(x,g,n,vis,mark))
                    return true;
                mark[x]=false;
            }
            else
                return true;
        }
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& preReq) {
        vector<vector<int>> g(n);
        for(int i=0;i<preReq.size();i++){
            if(preReq[i][0]!=preReq[i][1])
                g[preReq[i][1]].push_back(preReq[i][0]);
        }
        bool vis[n];
        bool mark[n];
        memset(vis,false,sizeof(vis));
        memset(mark,false,sizeof(mark));
        for(int i=0;i<n;i++){ 
            if(!vis[i])
                if(isCycle(i,g,n,vis,mark))
                    return false;
        }
        return true;
    }
};