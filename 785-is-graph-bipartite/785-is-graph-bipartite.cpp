class Solution {
public:
    
    bool bfs(vector<vector<int>>& graph, vector<int> &res, int i){
        
        queue<int> q;
        q.push(i);
        res[i]=0;
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            for(auto x: graph[cur]){
                if(res[x]==-1){
                    q.push(x);
                    res[x]=1-res[cur];
                }
                else{
                    if(res[x]==res[cur])
                        return false;;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> res(n, -1);
        
        for(int i=0; i<n; i++){
            if(res[i]==-1){
                if(!bfs(graph, res, i))
                    return false;
            }
        }

        return  true;
        
    }
};