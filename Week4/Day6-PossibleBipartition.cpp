class Solution {
public:
    
    bool possibleBipartition(int N, vector<vector<int>>& a) {
        vector<vector<int>> g(N+1);
        vector<int> col(N+1,0);
        vector<bool> vis(N+1,false);
        for(int i=0;i<a.size();i++){
            int x = a[i][0];
            int y = a[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                col[i]=1;
                q.push(i);
                
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    if(vis[u])
                        continue;
                    vis[u]=true;
                    for(auto v:g[u]){
                        if(col[u]==col[v])
                            return false;
                        if(col[u]==1)
                            col[v]=2;
                        else
                            col[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};